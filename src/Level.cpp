#include <raylib-cpp.hpp>
#include <iostream>
#include "targetPractise.hpp"
#include "level.hpp"

Level::Level()
{
}

Level::~Level()
{
}

void Level::Update() 
{
    /* update */

    /* draw */
    // DrawCube((Vector3){100, 0, 100}, 100, 100, 100, RED);
    DrawGrid(10, 1); 
    // DrawCubeWires((Vector3){10, -5, 10}, 100, 100, 100, BLACK);
}
