#include <iostream>

void partition(int *first, int *last, int *pivot) {
    while (first!=last) {
        while (*first > *pivot) {
            ++first;
        }
        do {
          --last;
        } while (*last < *pivot);
        std::swap(*first,*last);
        ++first;
    }
}

int main() {
    int vet[] = {-5, 7, 10, 7, 8, 9, 1, 7, -2, 3};
    partition(std::begin(vet), std::end(vet), std::begin(vet) + 3);
    return 0;
}