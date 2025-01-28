#include <iostream>

int main() {

    // allocate mem on stack. mem will release when scope is over
    int example[5];
    for (int i = 0; i < 5; i++) example[i] = i * 1024;
    // allocate on heap. need delete manually.
    int* another = new int[5];
    for (int i = 0; i < 5; i++) another[i] = i * 1024;
    delete[] another;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}