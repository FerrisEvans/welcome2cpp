#include <iostream>

class Entity {
public:
    float x, y;

    // if we don't want default constructor
    // Entity() = delete;
    Entity() : x(0), y(0) {}
    Entity(const float x, const float y) : x(x), y(y) {}

    void Print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    const Entity e(10.0f, 5.0f);
    e.Print();
    return 0;
}
