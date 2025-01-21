#include <iostream>

struct Entity {
    int x, y;

    void print() {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

struct StaticEntity {
    static int x ,y;

    static void print() {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int StaticEntity::x ,StaticEntity::y;

int main() {

    Entity e;
    e.x = 2;
    e.y = 3;

    Entity e1 = { 5, 8 };

    e.print();
    e1.print();

    StaticEntity::x = 0;
    StaticEntity::y = -1;
    StaticEntity::print();
    return 0;
}