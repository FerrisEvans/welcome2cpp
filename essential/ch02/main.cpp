#include <fstream>
#include <iostream>
#include <vector>

void swap(int &, int &);

void display(const std::vector<int> &, std::ostream & = std::cout);

void bubble_sort(std::vector<int>);

const std::vector<int> *fibon_seq(int);

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

void display(const std::vector<int> &vec, std::ostream &os) {
    for (int i = 0; i < 8; i++) os << vec[i] << " ";
    os << std::endl;
}

const std::vector<int> *fibon_seq(int size) {
    // 局部静态对象
    static std::vector<int> elems;
    const int max_size = 1024;

    if (size <= 0 || size > max_size) {
        std::cerr << "Invalid size " << size << std::endl;
        return 0;
    }

    // 如果size等于或小于elems.size()就不必重新计算了
    for (int i = elems.size(); i < size; i++) {
        if (i == 0 || i == 1) elems.push_back(1);
        else elems.push_back(elems[i - 1] + elems[i - 2]);
    }

    return &elems;
}

// 对文件的读写操作
std::ofstream ofil("text_out1.txt");

void bubble_sort(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i] > vec[j]) {
                ofil << "about to call swap!" << "i: " << i << " j: " << j << '\t' << " swapping: " << vec[i] <<
                        " with " << vec[j] << std::endl;
                swap(vec[i], vec[j]);
            }
        }
    }
}
