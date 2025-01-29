#include <iostream>

void string();

int main() {

    // allocate mem on stack. mem will release when scope is over
    int example[5];
    for (int i = 0; i < 5; i++) example[i] = i * 1024;
    // allocate on heap. need delete manually.
    int* another = new int[5];
    for (int i = 0; i < 5; i++) another[i] = i * 1024;
    delete[] another;
    std::cout << "Hello, World!" << std::endl;
    string();
    return 0;
}

void string() {
    const char* s = "Hello, World!";
    std::cout << s << std::endl;
    char c[6] = {'a', 'b', 'c', 'd', 'e', 0};
    std::cout << c << std::endl;
}