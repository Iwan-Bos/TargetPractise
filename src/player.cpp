#include <raylib-cpp.hpp>
#include <iostream>
#include "targetPractise.hpp"
#include "player.hpp"

Player::Player()
{
    // Define the camera
    camera = { 0 };
    camera.position = (Vector3){ 0.0f, 1.0f, 0.00000001f };     // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };              // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };                  // Camera up vector (rotation towards target)
    camera.fovy = 110.0f;                                       // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                     // Camera mode type
}

Player::~Player()
{

}

void Player::Update() 
{
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
}
