#include <raylib-cpp.hpp>
#include "targetPractise.hpp"
#include "levelManager.hpp"

int main() {
    // Initialization
    //----------------
    // Set starting positions
    Vector3 cubePos = { 0.0f, 0.0f, 0.0f };

    // Construct LevelManager
    LevelManager lMnger;
    Camera3D camera;

    // camera

    // Create the program window
    raylib::Color textColor(GREEN);
    raylib::Window w(SCREENWIDTH, SCREENHEIGHT, "");
    
    DisableCursor();
    SetTargetFPS(360);

    // Main program loop
    //-------------------
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        /* Update */
        lMnger.Update();
        camera = lMnger.GetCamera();
        
        /* Draw */
        BeginDrawing();

            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
                
                /* 3D Drawing */
                
                // TODO: MOVE TO LEVEL 1
                DrawGrid(20, 1.0f);

            EndMode3D();

            /* 2D Drawing */
            // TODO: MOVE INFO BOXES TO GUI RELATED CLASSES 
            // Draw camera info box
            DrawRectangle(15, 5, 195, 75, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines(15, 5, 195, 75, BLUE);

            DrawText("Camera status:", 25, 15, 10, BLACK);
            DrawText(TextFormat("- Position: (%06.3f, %06.3f, %06.3f)", camera.position.x, camera.position.y, camera.position.z), 25, 30, 10, BLACK);
            DrawText(TextFormat("- Target: (%06.3f, %06.3f, %06.3f)", camera.target.x, camera.target.y, camera.target.z), 25, 45, 10, BLACK);
            DrawText(TextFormat("- Up: (%06.3f, %06.3f, %06.3f)", camera.up.x, camera.up.y, camera.up.z), 25, 60, 10, BLACK);

        EndDrawing();
    }

    // De-Initialization
    //-------------------
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
