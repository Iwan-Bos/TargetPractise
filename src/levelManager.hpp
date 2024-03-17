#include "player.hpp"
#include "target.hpp"

class LevelManager
{
private:
    Player * player;
    Target * target0;
public:
    LevelManager(Model modelTarget, Model modelShuriken);
    ~LevelManager();
    void Update();
    Camera3D GetCamera();
    void DrawUI();
};
