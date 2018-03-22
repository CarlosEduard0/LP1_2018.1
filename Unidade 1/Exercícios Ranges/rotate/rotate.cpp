#include <iostream>

void rotate(int *first, int *n_first, int *last) {
    for(int i = 0; i < n_first - first; i++) {
        int j, temp = first[0];
        for(j = 0; j < last - first - 1; j++) {
            first[j] = first[j + 1];
        }
        first[j] = temp;
    }
}

void rotate_teste(int *first) {}

int main() {
    int vet[] = {1, 2, 3, 4, 5, 6, 7};
    rotate(std::begin(vet), std::begin(vet) + 2, std::end(vet));
    return 0;
}