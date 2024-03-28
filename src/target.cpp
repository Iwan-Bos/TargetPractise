#include <raylib-cpp.hpp>
#include <iostream>
#include "targetPractise.hpp"
#include "target.hpp"

Target::Target(Model modelTarget)
{
    if (DEBUG) { std::cout << "DEBUG: target: constructor called" << "\n"; };
    model = modelTarget;
}

Target::~Target()
{
    if (DEBUG) { std::cout << "DEBUG: target: deconstructor called" << "\n"; };
}

void Target::Update(Vector3 modelPosition)
{
    // update position
    pos = modelPosition;

    // draw model
    DrawModel(model, pos, 1, WHITE);
}

BoundingBox Target::GetBoundary()
{
    return GetModelBoundingBox(model);
}
