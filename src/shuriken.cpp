#include <raylib-cpp.hpp>
#include "targetPractise.hpp"
#include "shuriken.hpp"

Shuriken::Shuriken(Vector3 initVel, Model modelShuriken)
{
    // model
    model = modelShuriken;
    // movement
    vel = initVel;
    pos = (Vector3){0,1,0};
    acc = (Vector3){0,0,0};
}

Shuriken::~Shuriken()
{
}

void Shuriken::Update()
{
    /* Movement calculation */
    float deltaTime = GetFrameTime();   // Get deltaTime
    acc -= (Vector3){0,.98,0};          // Apply gravity to the shuriken
    acc -= vel / 3 * 2 ;                // Apply drag to the shuriken 
    vel += acc * deltaTime;             // Compute velocity based on acceleration
    pos += vel * deltaTime;             // Compute new position based on velocity
    acc = 0;                            // Reset acceleration for next run

    /* Drawing */
    DrawModel(model, pos, 1.0f, WHITE);
}

void Shuriken::DrawUI()
{
    // Draw text containing velocity
    DrawText(TextFormat("Position: (%06.3f, %06.3f, %06.3f)", pos.x, pos.y, pos.z), SCREENWIDTH/2, SCREENHEIGHT/2, 20, BLACK);
    DrawText(TextFormat("Velocity: (%06.3f, %06.3f, %06.3f)", vel.x, vel.y, vel.z), SCREENWIDTH/2, SCREENHEIGHT/2+20, 20, BLACK);
}
