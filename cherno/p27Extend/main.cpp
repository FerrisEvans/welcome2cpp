#include <iostream>

class Entity {
public:
    float X, Y;

    void Move(float xa, float ya) {
        X += xa;
        Y += ya;
    }

    virtual std::string GetName() { return "Entity"; }
};

class Player : public Entity {
    std::string m_Name;
public:
    Player() : Entity() {
        m_Name = "Player";
        X = Y = 0;
    }

    std::string GetName() override { return m_Name; }
};

void PrintName(Entity* e);

int main() {
    Player player;
    player.Move(10, 10);
    std::cout << player.X << " " << player.Y << std::endl;
    std::cout << sizeof(player) << std::endl;

    Entity entity;
    PrintName(&entity);
    PrintName(&player);
    return 0;
}


void PrintName(Entity* e) {
    std::cout << e->GetName() << std::endl;
}