#include <iostream>

class Entity {
public:
    float X, Y;

    void Move(float xa, float ya) {
        X += xa;
        Y += ya;
    }
};

class Player : public Entity {
public:
    char* Name;
    Player() : Entity() {
        Name = "";
        X = Y = 0;
    }
};

int main() {
    Player player;
    player.Move(10, 10);
    std::cout << player.X << " " << player.Y << std::endl;
    std::cout << sizeof(player) << std::endl;
    return 0;
}