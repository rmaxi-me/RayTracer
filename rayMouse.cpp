#include <iostream>
#include <raylib.h>
#include <unistd.h>
#include <raymath.h>
#include <vector>
// - 0.774324 - 0.41328 - 0.47919 20 20 20

struct data
{
    int x,y;
    Color color;
};

#define FLT_MAX 340282346638528859811704183484516925440.0f // Maximum value of a float, from bit pattern 01111111011111111111111111111111

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera");

    Camera camera = {0};
    camera.position = (Vector3){20.0f, 20.0f, 20.0f}; // Camera position
    camera.target = (Vector3){0.0f, 8.0f, 0.0f};      // Camera looking at point
    camera.up = (Vector3){0.0f, 1.6f, 0.0f};          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                              // Camera field-of-view Y
    camera.type = CAMERA_PERSPECTIVE;                 // Camera mode type
    SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode


    Ray ray = {0}; // Picking ray
    Vector3 ta = (Vector3){-25.0, 0.5, 0.0};
    Vector3 tb = (Vector3){-4.0, 2.5, 1.0};
    Vector3 tc = (Vector3){-8.0, 6.5, 0.0};

    bool hitTriangle = false;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    Vector3 center {0};
    float radius = 100;

    std::vector<data> drawData;

    while (!WindowShouldClose())
    {
        Vector3 forward = Vector3Normalize(Vector3Subtract(camera.target, camera.position)); // (target - origin).normalized();
        Vector3 right = Vector3Normalize(Vector3CrossProduct(forward, camera.up));  // cross(forward, upguide).normalized();
        Vector3 up = Vector3CrossProduct(right, forward);      // cross(right, forward)

        UpdateCamera(&camera); // Update camera
        
        RayHitInfo nearestHit = {0};
        char *hitObjectName = "None";
        nearestHit.distance = FLT_MAX;
        nearestHit.hit = false;
        Color cursorColor = WHITE;

        BeginDrawing();
        ClearBackground(BLACK);
//400 255

        BeginMode3D(camera);
        // Ray plop = GetMouseRay(GetMousePosition(), camera);
        // std::cout << "i = " << GetMousePosition().x << "j = " << GetMousePosition().y << std::endl;
        // std::cout << plop.direction.x << std::endl;
        // std::cout << plop.direction.y << std::endl;
        // std::cout << plop.direction.z << std::endl;
        // std::cout << plop.position.x << std::endl;
        // std::cout << plop.position.y << std::endl;
        // std::cout << plop.position.z << std::endl;

        for (int i = 0; i < 800; i++)
        {
            for (int j = 0; j < 450; j++)
            {
                float aspectRatio = screenWidth / screenHeight;
                Vector2 screenCord{(2.0f * i) / screenWidth - 1.0f, (-2.0f * j) / screenHeight + 1.0f};
                float h = tan((camera.fovy * PI / 180.0f));
                float w = h * aspectRatio;

                Vector3 t1 = Vector3Scale(Vector3Scale(right, w), screenCord.x /*Pixel I*/);
                Vector3 t2 = Vector3Scale(Vector3Scale(up, h), screenCord.y /*Pixel J*/);
                Vector3 direction = Vector3Add(forward, Vector3Add(t1, t2));
                Ray tmp{camera.position, Vector3Normalize(direction)};
                // std::cout << tmp.direction.x << std::endl;
                // std::cout << tmp.direction.y << std::endl;
                // std::cout << tmp.direction.z << std::endl;
                // std::cout << tmp.position.x << std::endl;
                // std::cout << tmp.position.y << std::endl;
                // std::cout << tmp.position.z << std::endl;
                // std::cout << "i = " << i << "j = " << j << std::endl;

                bool plop = CheckCollisionRaySphere(tmp, ta, 10.0f);
                if (plop == true) {
                    std::cout << "i = " << i << "j = " << j << std::endl;
                    drawData.push_back({i, j, PURPLE});
                } //else
                //    drawData.push_back({i, j, BLACK});
                // RayHitInfo triHitInfo = GetCollisionRayTriangle(ray, ta, tb, tc);
                // if (triHitInfo.hit) {
                //     throw;
                //     std::cout << "i = " << i << "j = " << j << std::endl;
                // }
            }
        }
       DrawSphere(ta, 10.0f, BLUE);
    //    DrawLine3D(ta, tb, PURPLE);
    //    DrawLine3D(tb, tc, PURPLE);
    //    DrawLine3D(tc, ta, PURPLE);
    //     DrawGrid(20, 5.0f);
        EndMode3D();

        std::cout << "size " << drawData.size() << std::endl;
        for (auto &i : drawData)
        {
            DrawPixel(i.x, i.y, RED);
        }
        

        EndDrawing();
        sleep(1);
    }

    CloseWindow();
    return 0;
}