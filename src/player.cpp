#include <raylib-cpp.hpp>
#include "targetPractise.hpp"
#include "player.hpp"

Player::Player(Model modelShuriken)
{
    // Hand model to shuriken constructor
    shurikenModel = modelShuriken;

    // Define the camera
    camera = { 0 };
    camera.position = PLAYERPOSITION;               // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };  // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };      // Camera up vector (rotation towards target)
    camera.fovy = 70.0f;                            // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;         // Camera mode type
}

Player::~Player()
{
    // TODO: DELETE ALL ACTIVE SHURIKEN IN LIST SHURIKENS HERE
}

void Player::Update() 
{
    // Controls
    //==========
    // Camera controls
    UpdateCameraPro(&camera, 
        (Vector3){0.0f, 0.0f, 0.0f},
        (Vector3){
            GetMouseDelta().x*0.05f,    // yaw
            GetMouseDelta().y*0.05f,    // pitch
            0.0f                        // roll
        },
        0.0f                            // zoom
    );

    // Shooting controls
    if (IsMouseButtonPressed(0))    // Check if left mouse button has been pressed once
    {
        initVel = (raylib::Vector3)
        {
            camera.target.x, 
            camera.target.y - camera.position.y, 
            camera.target.z
        }.Normalize() * 10.0f; // << Shuriken velocity multiplier

        Shuriken * proj = new Shuriken(initVel, shurikenModel); // Construct a new shuriken
        shurikens.push_back(proj);  // Add the shuriken to the shuriken list
    }

    // Update
    //========
    // Update each shuriken
    for (Shuriken* i : shurikens)
    {   
        i->Update();
    }
}

void Player::DrawUI()
{
    for (Shuriken* i : shurikens) { i->DrawUI(); };
}
