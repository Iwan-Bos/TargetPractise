#include <raylib-cpp.hpp>
#include <iostream>
#include "targetPractise.hpp"
#include "levelManager.hpp"

LevelManager::LevelManager(Model modelTarget, Model modelShuriken)
{
    player = new Player(modelShuriken);
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
    this->target0->Update((Vector3){10,1,0}); // TODO: MOVE WHERE THE POSITION IS ENTERED
    DrawGrid(10, 0.5);
}

void LevelManager::DrawUI()
{
    player->DrawUI();
}

Camera3D LevelManager::GetCamera()
{
    return player->camera;
}
