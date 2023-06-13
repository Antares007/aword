#include "raylib.h"
#include <math.h>

#define NUM_STEPS 30
#define STEP_HEIGHT 20
#define STEP_WIDTH 40
#define PERSPECTIVE_SCALE 0.8f
/*
      b 736, aw 900, aw 522, aw 1022, o 99
                     tab 444,
                     aw 818,
                     aw 342,
                     aw 956,
                     aw 818,
                     aw 342,
                     aw 956,
                     o 99
*/
int main(void)
{
    // Initialize the window and the 2D camera
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Spiral Stairways with Perspective");
    Camera2D camera = { 0 };
    camera.target = (Vector2){ 0 };
    camera.offset = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60); // Set desired frame rate

    while (!WindowShouldClose()) // Main game loop
    {
        // Update

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode2D(camera);

        // Draw the spiral stairways
        float angleStep = 360.0f / NUM_STEPS;
        float radius = 0.0f;
        float angle = 0.0f;
        float perspectiveScale = 1.0f;

        for (int i = 0; i < NUM_STEPS; i++)
        {
            float x = radius * cos(DEG2RAD * angle);
            float y = radius * sin(DEG2RAD * angle);
            float width = STEP_WIDTH * perspectiveScale;
            float height = STEP_HEIGHT;

            DrawRectangle(x - width * 0.5f, y, width, height, RED);

            radius += STEP_HEIGHT;
            angle += angleStep;
            perspectiveScale *= PERSPECTIVE_SCALE;
        }

        EndMode2D();

        EndDrawing();
    }

    CloseWindow(); // Close the window

    return 0;
}
