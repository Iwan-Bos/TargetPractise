#include "player.hpp"

class LevelManager
{
private:
    Player * player;
public:
    LevelManager();
    ~LevelManager();
    void Update();
    Camera3D GetCamera();
};
