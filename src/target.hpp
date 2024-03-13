class Target
{
private:
    Model model;
    Vector3 position;
public:
    Target(Model modelTarget);
    ~Target();
    void Update(Vector3 modelPosition);
};
