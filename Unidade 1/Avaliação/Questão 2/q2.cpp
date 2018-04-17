#include <iostream>

using UnaryPredicate = bool(const int *);

std::pair<int *, int *> array_selected(const int *first, const int *last, UnaryPredicate *p) {
    int elementos = 0;
    int *ints = new int;
    while(first != last) {
        if(p(first)) {
            elementos++;
            ints = (int *) realloc(ints, elementos);
            ints[elementos - 1] = *first;
        }
        first++;
    }
    return std::make_pair(&ints[0], &ints[elementos]);
}

bool pred(const int *a) {
    return *a > 5;
}

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::pair<int *, int *> par = array_selected(std::begin(A), std::end(A), pred);
    for(int *i = par.first; i != par.second; i++) {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
    return 0;
}