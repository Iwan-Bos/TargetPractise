class Target
{
private:
    Model model;
    BoundingBox bounds;
public:
    raylib::Vector3 pos;
    Target(Model modelTarget);
    ~Target();
    void Update(Vector3 modelPosition);
    BoundingBox GetBoundary();
};
