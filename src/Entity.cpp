#include <raylib-cpp.hpp>
#include <iostream>
#include "targetPractise.hpp"

class Entity {
private:
public:
    Entity() {
        std::cout << "Constructor called" << std::endl;
    }
    ~Entity() {
        std::cout << "Destructor called" << std::endl;
    }
};