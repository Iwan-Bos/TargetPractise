#include "player.hpp"
#include "target.hpp"

class LevelManager
{
private:
    Player * player;
    Target * target0;
    int score;
    float distance;
    std::list<Shuriken*> shurikens;
    std::list<Shuriken*> collidedShurikens;
public:
    LevelManager(Model modelTarget, Model modelShuriken);
    ~LevelManager();
    void Update();
    Camera3D GetCamera();
    void DrawUI();
};
