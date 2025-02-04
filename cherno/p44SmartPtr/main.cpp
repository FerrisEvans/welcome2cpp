#include <iostream>

class Entity {
public:
    Entity() {
        std::cout << "Entity created" << std::endl;
    }

    ~Entity() {
        std::cout << "Entity destroyed" << std::endl;
    }

    void Print() {
        std::cout << "Entity printed" << std::endl;
    }
};

int main() {

    {
        // c++14 版本以后 可以使用make_unique构造函数来创建unique_ptr
        // std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        std::unique_ptr<Entity> unique_entity(new Entity());
        unique_entity->Print();

        std::shared_ptr<Entity> shared_entity;
        {
            shared_entity = std::make_shared<Entity>();
            shared_entity->Print();
        }
    }


    return 0;
}
