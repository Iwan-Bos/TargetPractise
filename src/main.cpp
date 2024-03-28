#include <raylib-cpp.hpp>
#include "targetPractise.hpp"
#include "levelManager.hpp"

int main() {
    // Initialization
    //----------------
    // Create the program window
    raylib::Color textColor(GREEN);
    raylib::Window w(SCREENWIDTH, SCREENHEIGHT, "Target Practise");
    DisableCursor();
    SetTargetFPS(360);

    // Load models
    // Target
    Model modelTarget = LoadModel("./assets/models/target.obj");                // Load target model
    Texture2D texture = LoadTexture("./assets/models/target.png");              // Load target texture
    modelTarget.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;      // Assign target texture to model
    // Shuriken
    Model modelShuriken = LoadModel("./assets/models/shuriken.obj");            // Load shuriken model
    texture = LoadTexture("./assets/models/shuriken.png");                      // Load shuriken texture
    modelShuriken.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;    // Assign shuriken texture to model

    
    LevelManager levelManager(modelTarget, modelShuriken); // make a new instance of levelmanager
    Camera3D camera; // Define camera

    // Main program loop
    //-------------------
    while (!w.ShouldClose())    // Detect window close button or ESC key
    {
        camera = levelManager.GetCamera();  // Get the camera in order to start 3D mode   
        BeginDrawing();                     // Raylib draw start

            ClearBackground(RAYWHITE);  // clear frame

            BeginMode3D(camera);        // enter 3D mode
            levelManager.Update();      // Update/Draw 3D related objects
            EndMode3D();                // exit 3D mode

            levelManager.DrawUI();      // Update/Draw 2D related objects

            DrawCircle(SCREENWIDTH/2, SCREENHEIGHT/2, 3.0f, Fade(BLACK, 0.9f)); // Draw crosshair 
            
            // TODO: MOVE vvTHISvv DEBUG INFO TO ANOTHER CLASS 
            DrawRectangle(15, 5, 195, 75, Fade(SKYBLUE, 0.5f)); // Draw camera info box
            DrawRectangleLines(15, 5, 195, 75, BLUE);           // Draw info box outline
            DrawText("Camera status:", 25, 15, 10, BLACK);
            DrawText(TextFormat("- Position: (%06.3f, %06.3f, %06.3f)", camera.position.x, camera.position.y, camera.position.z), 25, 30, 10, BLACK);
            DrawText(TextFormat("- Target: (%06.3f, %06.3f, %06.3f)", camera.target.x, camera.target.y, camera.target.z), 25, 45, 10, BLACK);
            

        EndDrawing();   // Raylib draw end
    }

    // De-Initialization
    //-------------------
    // Unload models from memory (RAM and/or VRAM)
    UnloadModel(modelTarget);
    UnloadModel(modelShuriken);
    // Close window and OpenGL context
    CloseWindow();  

    return 0;
}
