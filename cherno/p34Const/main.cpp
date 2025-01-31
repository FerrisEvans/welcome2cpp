#include <iostream>

class Entity {
private:
    int m_X, m_Y;
    mutable int var;

public:
    int GetX() const {
        // we can modify a mutable var in a const method
        var = m_X;
        return m_X;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
