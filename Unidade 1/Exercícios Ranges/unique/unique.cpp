#include <iostream>

int* unique(int *first, int *last) {
    int *n_last = first;
    while(first != last) {
        if(*n_last != *first) {
            *(++n_last) = *first;
        }
        first++;
    }
    return n_last;
}

int main() {
    int vet[] = {1, 1, 3, 4, 4, 5, 5};
    int *last = unique(std::begin(vet), std::end(vet));
    return 0;
}