#include <iostream>

struct Vertex {
    float x, y, z;
};

std::ostream& operator<<(std::ostream& os, const Vertex& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

int main() {

    std::vector<Vertex> vertices;
    vertices.push_back({1, 1, 1});
    vertices.push_back({2, 2, 2});
    vertices.push_back({3, 3, 3});
    vertices.push_back({4, 4, 4});
    vertices.push_back({5, 5, 5});
    vertices.push_back({6, 6, 6});
    // for (int i = 0; i < vertices.size(); ++i) std::cout << vertices[i] << std::endl;

    vertices.erase(vertices.begin() + 3, vertices.end());
    for (const Vertex& vertice : vertices) std::cout << vertice << std::endl;
    vertices.clear();
    return 0;
}