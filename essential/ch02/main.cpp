#include <iostream>

void swap(int &, int &);

int main() {
    int ival = 1024; // 对象，类型为int
    int &rval = ival; // reference，代表一个int对象

    int jval = 4096;
    rval = jval;
    std::cout << ival << std::endl;

    int *pi = &ival; // pointer，指向一个int对象
    int *pj = &rval;
    bool b = *pj == *pi;
    std::cout << b << std::endl;
    std::cout << "===============" << std::endl;

    int x = 1, y = 2;
    swap(x, y);
    std::cout << "x = " << x
            << " y = " << y
            << std::endl;

    return 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
