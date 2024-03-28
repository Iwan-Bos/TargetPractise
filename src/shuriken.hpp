#ifndef SHURIKEN_H
#define SHURIKEN_H

#include <raylib-cpp.hpp>

class Shuriken
{
private:
    Model model;            // Shuriken model
    raylib::Vector3 vel;    // Velocity
    raylib::Vector3 acc;    // Acceleration
public:
    Shuriken(raylib::Vector3 initVel, Model modelShuriken); // Constructor
    ~Shuriken();                                            // Deconstructor
    void Update();
    void DrawUI();
    raylib::Vector3 pos;    // Position (could be made into getter as it is only read outside of Shuriken).
    char hit;
    
};

#endif
