#include "player.hpp"
#include "level.hpp"

class LevelManager
{
private:
    Player * player;
    Level * level1;
    Level levels[1];
public:
    LevelManager();
    ~LevelManager();
    void Update();
    Camera3D GetCamera();
};
