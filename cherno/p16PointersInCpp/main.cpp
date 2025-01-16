#include <iostream>

#define LOG(x) std::cout << x << std::endl;

void allocate();

int main() {

    int var = 8;
    int *ptr = &var;
    *ptr = 10;
    LOG(var)
    return 0;
}

void allocate() {
    char* buffer = new char[8];
    memset(buffer, 0, 8);
    delete[] buffer;
}
