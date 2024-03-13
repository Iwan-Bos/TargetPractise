#include <raylib-cpp.hpp>
#include <iostream>
#include "targetPractise.hpp"
#include "levelManager.hpp"

LevelManager::LevelManager(Model modelTarget)
{
    player = new Player();
    target0 = new Target(modelTarget); // TODO: ADD SOMETHING TO ADDS TARGETS DYNAMICALLY 
}

LevelManager::~LevelManager()
{
    delete player;
    delete target0; // TODO: ADD SOMETHING TO DELETE TARGETS DYNAMICALLY
}

void LevelManager::Update() 
{
    this->player->Update();
    this->target0->Update((Vector3){10,0,0}); // TODO: POSITION HERE I NONO WANNA
    DrawGrid(10, 0.5);
}

Camera3D LevelManager::GetCamera()
{
    return player->camera;
}
