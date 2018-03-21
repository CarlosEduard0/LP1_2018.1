#include <iostream>

void scalar_multiplication(int *first, int *last, int scalar) {
    while(first != last) {
        *first *= scalar;
        first++;
    }
}

int main(){
    int vet[] = {1, 2, -3, -4, 5, -6};
    scalar_multiplication(std::begin(vet), std::end(vet), 3);
    return 0;
}