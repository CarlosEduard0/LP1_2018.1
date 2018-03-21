#include <iostream>

int* compact(int *first, int *last) {
    int nulos = 0;
    while(first != last) {
        for(int *i = first + 1; i != last; i++) {
            if(*first <= 0 && *i > 0) {
                std::swap(*first, *i);
            }
        }
        if(*first <= 0) {
            nulos++;
        }
        first++;
    }
    return last - nulos;
}

int main() {
    int vet[] = { 1, -2, 3, 4, -5};
    int *last = compact(std::begin(vet), std::end(vet));
    for(int *i = std::begin(vet); i != last; i++) {
        std::cout << *i << std::endl;
    }
    return 0;
}