#include <iostream>

const int* min(const int *first, const int *last) {
    const int *minimo = first;
    while(first != last) {
        if(*first < *minimo) {
            minimo = first;
        }
        first++;
    }
    return minimo;
}

int main() {
    int vet[] = {1, 2, -3, -4, 5, -6};
    std::cout << *min(std::begin(vet), std::end(vet)) << std::endl;
    return 0;
}