#include <list>
#include "shuriken.hpp"

class Player
{
private:
    raylib::Vector3 initVel;
    Model shurikenModel;
    std::list<Shuriken*> shurikens;
public:
    Player(Model modelShuriken);
    ~Player();
    void Update();
    void DrawUI();
    Camera3D camera;
    std::list<Shuriken*>& GetShurikenList();
    void SetShurikenList(std::list<Shuriken*> alteredShurikens);
};
