#include <iostream>

#define LOG(x) std::cout << x << std::endl;

void allocate();

void ref();

void pointer();

void increase(int &);

int main() {
    int a = 1;
    increase(a);
    LOG(a);
    return 0;
}

void pointer() {
    int var = 8;
    int *ptr = &var;
    *ptr = 10;
    LOG(var)
}

void allocate() {
    char *buffer = new char[8];
    memset(buffer, 0, 8);
    delete[] buffer;
}

void ref() {
    int a = 5;
    int &ref = a;

    ref = 2;
    LOG(a)
}


void increase(int &val) {
    val++;
}
