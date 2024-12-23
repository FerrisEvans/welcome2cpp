#include <fstream>
#include <iostream>
#include <vector>

void swap(int &, int &);
void display(std::vector<int>);
void bubble_sort(std::vector<int>);

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
    std::cout << "===============" << std::endl;

    int ia[] = {8, 34, 3, 13, 1, 21, 5, 2};
    std::vector<int> vec(ia, ia + 8);
    bubble_sort(vec);
    display(vec);

    return 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void display(std::vector<int> vec) {
    for (int i = 0; i < 8; i++) std::cout << vec[i] << " ";
    std::cout << std::endl;
}

// 对文件的读写操作
std::ofstream ofil("text_out1.txt");
void bubble_sort(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i+1; j < vec.size(); j++) {
            if (vec[i] > vec[j]) {
                ofil << "about to call swap!" << "i: " << i << " j: " << j << '\t' << " swapping: " << vec[i] << " with " << vec[j] << std::endl;
                swap(vec[i], vec[j]);
            }
        }
    }
}
