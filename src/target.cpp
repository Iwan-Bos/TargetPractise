#include <raylib-cpp.hpp>
#include <iostream>
#include "targetPractise.hpp"
#include "target.hpp"

Target::Target(Model modelTarget)
{
    model = modelTarget;
}

Target::~Target()
{

}

void Target::Update(Vector3 modelPosition)
{
    // update position
    position = modelPosition;

    // draw model
    DrawModel(model, position, 1, WHITE);
    DrawModelWires(model, position, 1, GREEN);
}
