#include <iostream>
#include <vector>

// TIP 以下是六种数列的前八个元素值 <br/>
// Fibonacci: 1, 1, 2, 3, 5, 8, 13, 21 <br/>
// Lucas: 1, 3, 4, 7, 11, 18, 29, 47 <br/>
// Pell: 1, 2, 5, 12, 29, 70, 169, 408 <br/>
// Triangular: 1, 3, 6, 10, 15, 21, 28, 36 <br/>
// Square: 1, 4, 9, 16, 25, 36, 49, 64 <br/>
// Pentagonal: 1, 5, 12, 22, 35, 51, 70, 92 <br/>
// 我们的程序必须能够显示数列中的任意两个元素值，让用户猜测下一个元素值是什么。
// 如果用户猜对了，并且愿意继续下去，程序便接着显示第二组、第三组……元素值。<br/>
// 如果接着出现的每组元素都出自同一数列，那么一旦用户找出其中一组答案，他就能够找出所有答案，丧失了趣味性。
// 所以我们应该在程序主循环的每次迭代中，挑选不同的数列。<br/>
// 现在，我们要显示六组元素对，每一组来自不同的数列。我们希望在显示每组元素的同时，不必知道正在显示的是哪一种数列。
// 每次迭代都必须存取三个数：元素对中的两个元素值，以及数列中出现的第三个元素值。


void container();

void pointer();

int main() {
    container();
    pointer();
    return 0;
}

void container() {
    const int seq_size = 18;
    int pell_seq[seq_size];
    pell_seq[0] = 1;
    pell_seq[1] = 2;
    for (int ix = 2; ix < seq_size; ++ix) {
        pell_seq[ix] = 2 * pell_seq[ix - 1] + pell_seq[ix - 2];
    }

    int elem_seq[seq_size] = {
        1, 2, 3, // Fibonacci
        3, 4, 7, // Lucas
        2, 5, 12, // Pell
        3, 6, 10, // Triangular
        4, 9, 16, // Square
        5, 12, 22 // Pentagonal
    };

    int cur_tuple = 0;
    bool next_seq = true;

    while (next_seq && cur_tuple < seq_size) {
        int usr_guess;
        std::cout << "The first two elements of the sequence are: "
                << elem_seq[cur_tuple] << ", "
                << elem_seq[cur_tuple + 1]
                << "\nWhat is the next element?"
                << std::endl;
        std::cin >> usr_guess;
        if (usr_guess == elem_seq[cur_tuple]) {
            std::cout << "Correct!" << std::endl;
        }
        char usr_rsp;
        std::cin >> usr_rsp;
        if (usr_rsp == 'n' || usr_rsp == 'N') {
            next_seq = false;
        } else {
            cur_tuple += 3;
        }
    }
}

void pointer() {
    const int seq_cnt = 6;
    std::vector<int> fibonacci, lucas, pell,triangular, square, pentagonal;
    // 一个指针数组，每个指针都指向vector<int>对象
    std::vector<int> *seq_addrs[seq_cnt] = {&fibonacci,  &lucas, &pell, &triangular, &square, &pentagonal};
    // seq_addrs是一个array，其元素类型为vector<int> *。seq_addrs[0]所持有的值是fibonacci vector的地址，seq_addrs[1]的值是lucas vector的地址，以此类推。
    std::vector<int> *current_vec = nullptr; // 一个未指向任何对象的指针，其地址值为0。有时候我们称之为null指针。任何指针都可以被初始化，或是令其值为0。
    // 我们通过一个索引值而非其名称来访问各个vector
    srand(seq_cnt);
    int seq_index = rand() % seq_cnt;
    // 所有要显示的元素都可以通过current_vec间接访问到。
    current_vec = seq_addrs[seq_index];


}
