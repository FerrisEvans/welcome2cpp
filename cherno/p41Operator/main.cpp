#include <iostream>

struct Vector2 {
    float x, y;

    Vector2(const float x, const float y) : x(x), y(y) {}

    Vector2 operator+(const Vector2 &other) const {
        return Vector2(this->x + other.x, this->y + other.y);
    }

    Vector2 operator*(const Vector2 &other) const {
        return Vector2(this->x * other.x, this->y * other.y);
    }

    bool operator==(const Vector2 &other) const {
        return this->x == other.x && this->y == other.y;
    }
};

std::ostream &operator<<(std::ostream &os, const Vector2 &v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main() {
    Vector2 position(4.0F, 5.0F);
    Vector2 speed(0.5F, 1.5F);
    Vector2 powerup(1.1F, 1.2F);
    Vector2 res = position + speed * powerup;
    std::cout << res << std::endl;
    return 0;
}