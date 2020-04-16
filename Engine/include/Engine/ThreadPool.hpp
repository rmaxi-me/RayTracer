/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <queue>
#include <vector>

#include <mutex>
#include <atomic>
#include <thread>

template<typename Ret, typename... Args>
class ThreadPool {
public:
    static std::uint32_t MaxHardwareConcurrent;
private:
    std::function<Ret(Args...)> m_worker;
    std::uint32_t m_maxConcurrent;

    std::vector<std::thread> m_threads{};
    std::queue<Args...> m_queue{};
    std::atomic_uint32_t m_running{0};
    std::mutex m_mutex{};

    void runTask(Args &&...args)
    {
        {
            std::lock_guard lockGuard(m_mutex);

            while (m_running >= m_maxConcurrent) {
                std::this_thread::yield();
            }
            ++m_running;
        }

        m_worker(args...);
        --m_running;
    }

public:
    explicit ThreadPool(std::function<Ret(Args...)> worker, std::uint32_t maxConcurrent = MaxHardwareConcurrent)
            : m_worker{worker}, m_maxConcurrent{maxConcurrent}
    {
        if (maxConcurrent > MaxHardwareConcurrent) {
            std::cerr << "WARNING: ThreadPool: " << maxConcurrent << '/' << MaxHardwareConcurrent << " threads scheduled\n";
        }
    }

    void queueTask(Args &&...args)
    {
        m_queue.push(std::forward<Args>(args)...);
    }

    void run()
    {
        while (true) {
            if (m_queue.empty())
                break;

            auto args = m_queue.front();
            m_threads.emplace_back(&ThreadPool<Ret, Args...>::runTask, this, args);
            m_queue.pop();
        }

        for (auto &thread : m_threads)
            thread.join();
    }
};

template<typename Ret, typename... Args>
std::uint32_t ThreadPool<Ret, Args...>::MaxHardwareConcurrent = std::thread::hardware_concurrency();
