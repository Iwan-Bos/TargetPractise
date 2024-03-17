#ifndef SHURIKEN_H
#define SHURIKEN_H

#include <raylib-cpp.hpp>

class Shuriken
{
private:
    Model model;                // Shuriken model
    raylib::Vector3 pos;        // Position
    raylib::Vector3 vel;        // Velocity
    raylib::Vector3 acc;        // Acceleration
public:
    Shuriken(Vector3 initVel, Model modelShuriken);
    ~Shuriken();
    void Update();
    void DrawUI();
};

#endif
