#include <raylib-cpp.hpp>
#include <iostream>
#include "targetPractise.hpp"
#include "levelManager.hpp"

// Constructor & Deconstructor
//=============================
LevelManager::LevelManager(Model modelTarget, Model modelShuriken)
{
    if (DEBUG) { std::cout << "DEBUG: levelManager: constructor called" << "\n"; };
    player = new Player(modelShuriken);
    target0 = new Target(modelTarget); // TODO: ADD SOMETHING TO ADDS TARGETS DYNAMICALLY IF MORE TARGETS ARE ADDED.
}
LevelManager::~LevelManager()
{
    if (DEBUG) { std::cout << "DEBUG: levelManager: deconstructor called" << "\n"; };
    delete player;
    delete target0; // TODO: ADD SOMETHING TO DELETE TARGETS DYNAMICALLY IF MORE TARGETS ARE ADDED.
}

void LevelManager::Update() 
{
    // Update children (technically this is incorrect as nothing keeps track of children (just like real life frfr ong so truee)).
    this->player->Update();
    this->target0->Update((raylib::Vector3){3,1,0}); // TODO: MOVE WHERE THE POSITION IS ENTERED.

    // Shuriken and targets "collision"
    //==================================
    shurikens = player->GetShurikenList(); // Get current list of shurikens from player, which handles the creation shurikens.

    // reverse order iterator for loop, as lists don't support random access.
    for (auto it = shurikens.rbegin(); it != shurikens.rend(); ++it)
    {
        (*it)->Update(); // Update shuriken.
        // TODO: MAKE ALL DISTANCES CONFIGURABLE FOR ALL AXES.
        float distance = target0->pos.Distance((*it)->pos); // Calculate distance between shuriken and target
        if (distance <= 0.6f) // If shuriken is close enough to a target:
        {
            collidedShurikens.push_back(*it); // Add shuriken to seperate list,
            score++; // And increase the score.
        }
    }
    for(Shuriken* j : collidedShurikens) // Loop through all shurikens in the seperate lists:
    {
        delete (j); // Delete the shuriken object,
        shurikens.remove(j); // And remove it from the list.
    }
    collidedShurikens.clear(); // Clear the sepeerate list,
    player->SetShurikenList(shurikens); // And update the original list.

    DrawGrid(10, 0.5); // Finally, draw a grid to not get motion sick :P
}
// Draw 2D elements.
void LevelManager::DrawUI()
{
    if (DEBUG) { DrawText(TextFormat("Score: (%06.3f)", score), SCREENHEIGHT/2 + 200, SCREENWIDTH/2, 10, BLACK); };
    player->DrawUI();
}
// Get the camera from player to start 3D mode in main.
Camera3D LevelManager::GetCamera()
{
    return player->camera;
}
