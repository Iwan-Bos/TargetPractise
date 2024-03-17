#include <list>
#include "shuriken.hpp"

class Player
{
private:
    raylib::Vector3 initVel;
    std::list<Shuriken*> shurikens;
    Model shurikenModel;
public:
    Player(Model modelShuriken);
    ~Player();
    void Update();
    void DrawUI();
    Camera3D camera;
};
