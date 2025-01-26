#include <iostream>

class Entity {
public:
    float X, Y;

    void Move(float xa, float ya) {
        X += xa;
        Y += ya;
    }

    virtual std::string GetName() { return "Entity"; }

    // pure virtual function. This will make Entity an abstract class. We can't make an instance for Entity.
    virtual std::string IGetName() = 0;
};

class Player : public Entity {
    std::string m_Name;
public:
    Player() : Entity() {
        m_Name = "Player";
        X = Y = 0;
    }

    std::string GetName() override { return m_Name; }

    std::string IGetName() override { return m_Name; }
};

void PrintName(Entity* e);
void PrintIName(Entity* e);

int main() {
    Player player;
    player.Move(10, 10);
    std::cout << player.X << " " << player.Y << std::endl;
    std::cout << sizeof(player) << std::endl;

    // Entity entity;
    // PrintName(&entity);
    // PrintIName(&entity);
    PrintName(&player);
    PrintIName(&player);
    return 0;
}


void PrintName(Entity* e) {
    std::cout << e->GetName() << std::endl;
}

void PrintIName(Entity* e) {
    std::cout << e->IGetName() << std::endl;
}