#include <raylib-cpp.hpp>
#include <iostream>
#include "targetPractise.hpp"
#include "shuriken.hpp"

Shuriken::Shuriken(raylib::Vector3 initVel, Model modelShuriken)
{
    if (DEBUG) { std::cout << "DEBUG: shuriken: constructor called" << "\n"; };

    // model
    model = modelShuriken;
    // movement
    vel = initVel;
    pos = (raylib::Vector3){0,1,0};
    acc = (raylib::Vector3){0,0,0};
    // data
    hit = 0;
}

Shuriken::~Shuriken()
{
    if (DEBUG) { std::cout << "DEBUG: shuriken: deconstructor called" << "\n"; };
}

void Shuriken::Update()
{
    // Movement calculation
    float deltaTime = GetFrameTime();   // Get deltaTime
    acc -= (Vector3){0,.98,0};          // Apply gravity to the shuriken
    acc.x -= vel.x / 3 * 2 ;            // Apply drag to the shuriken 
    acc.z -= vel.z / 3 * 2 ;            // Apply drag to the shuriken 
    vel += acc * deltaTime;             // Compute velocity based on acceleration
    pos += vel * deltaTime;             // Compute new position based on velocity
    acc = 0;                            // Reset acceleration for next run

    // Drawing
    DrawModel(model, pos, 1.0f, WHITE);
}

void Shuriken::DrawUI()
{
    if (DEBUG)
    {
        // Draw text withvelocity and position (will overlap with more than one shuriken)
        DrawText(TextFormat("Position: (%06.3f, %06.3f, %06.3f)", pos.x, pos.y, pos.z), SCREENWIDTH/2, SCREENHEIGHT/2, 20, BLACK);
        DrawText(TextFormat("Velocity: (%06.3f, %06.3f, %06.3f)", vel.x, vel.y, vel.z), SCREENWIDTH/2, SCREENHEIGHT/2+20, 20, BLACK);
    }
}
