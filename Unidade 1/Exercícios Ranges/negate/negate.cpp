#include <iostream>

void negate(int *first, int *last) {
    while(first != last) {
        *first *= -1;
        first++;
    }
}

int main() {
    int vet[] = {1, 2, -3, -4, 5, -6};
    negate(std::begin(vet), std::end(vet));
    return 0;
}