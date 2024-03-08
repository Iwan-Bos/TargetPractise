#include <raylib-cpp.hpp>
#include <iostream>
#include "targetPractise.hpp"
#include "levelManager.hpp"

LevelManager::LevelManager()
{
    player = new Player;
    level1 = new Level;
    levels[1] = {*level1};
}

LevelManager::~LevelManager()
{
    delete player;
    // TODO: DELETE LIST AND ALL ELEMENTS INSIDE IT
}

void LevelManager::Update() 
{
    this->player->Update(); // update player
    for (int i = 0; i < sizeof levels / sizeof levels[0]; i++)
    {
        try
        {
            levels[i].Update(); // update levels    
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

Camera3D LevelManager::GetCamera()
{
    return player->camera;
}
