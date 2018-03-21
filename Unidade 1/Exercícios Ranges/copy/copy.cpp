#include <iostream>

int* copy(const int *first, const int *last, int *d_first) {
    while(first != last) {
        *d_first = *first;
        first++;
        d_first++;
    }
    return d_first;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {0, 0, 0};
    int *b_last = copy(std::begin(a) + 1, std::begin(a) + 4, std::begin(b));
    for(int *i = std::begin(b); i != b_last; i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    return 0;
}