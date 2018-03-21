#include <iostream>

void reverse(int *first, int *last) {
    for(int i = 0; i < (last - first) / 2; i++) {
        std::swap(*(first + i), *(last - i - 1));
    }
}

int main() {
    int vet[] = {1, 2, 3, 4, 5};
    reverse(std::begin(vet), std::end(vet));
    return 0;
}