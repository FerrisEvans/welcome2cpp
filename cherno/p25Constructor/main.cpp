#include <iostream>

class Entity {
public:
    float x, y;

    // if we don't want default constructor
    // Entity() = delete;
    Entity() : x(0), y(0) {
        std::cout << "Entity created" << std::endl;
    }
    Entity(const float x, const float y) : x(x), y(y) {}

    ~Entity() {
        std::cout << "Entity deleted" << std::endl;
    }

    void Print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    const Entity e;
    e.Print();
    return 0;
}
