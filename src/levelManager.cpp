#include <raylib-cpp.hpp>
#include <iostream>
#include "targetPractise.hpp"
#include "levelManager.hpp"

LevelManager::LevelManager()
{
    player = new Player;
}

LevelManager::~LevelManager()
{
    delete player;
}

void LevelManager::Update() 
{
    // update player
    this->player->Update();
}
