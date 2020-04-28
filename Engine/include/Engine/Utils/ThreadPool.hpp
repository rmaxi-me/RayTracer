/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <iostream>
#include <functional>

#include <map>
#include <queue>

#include <mutex>
#include <atomic>
#include <thread>

template<typename Ret, typename... Args>
class ThreadPool {
public:
    static std::uint32_t MaxHardwareConcurrent;
private:
    std::function<Ret(const std::tuple<Args...> &)> m_worker;
    std::uint32_t m_maxConcurrent;

    std::vector<std::thread> m_threads{};
    std::queue<std::tuple<Args...>> m_queue{};
    std::atomic_uint32_t m_running{0};

    void runTask(const std::tuple<Args...> &args)
    {
        m_worker(args);
        --m_running;
    }

public:
    explicit ThreadPool(decltype(m_worker) worker, std::uint32_t maxConcurrent = MaxHardwareConcurrent)
            : m_worker{worker}, m_maxConcurrent{maxConcurrent}
    {
        if (maxConcurrent > MaxHardwareConcurrent) {
            std::cerr << "WARNING: ThreadPool: "
                      << maxConcurrent << '/' << MaxHardwareConcurrent << " threads scheduled\n";
        }
    }

    void queueTask(const std::tuple<Args...> &args)
    {
        m_queue.push(args);
    }

    void runAndWait()
    {
        while (!m_queue.empty()) {
            while (m_running >= m_maxConcurrent) {
                std::this_thread::yield();
            }
            ++m_running;

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
