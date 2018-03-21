#include <iostream>

int dot_product(const int *a_first, const int *a_last, const int *b_first) {
    int produto = 0;
    int i = 0;
    for(; a_first != a_last; a_first++, i++) {
        produto += (*a_first) * (*(b_first + i));
    }
    return produto;
}

int main() {
    int vet[] = {1, 3, -5, 4, -2, -1};
    int result = dot_product(std::begin(vet), std::begin(vet) + 3, std::begin(vet) + 3);
    std::cout << "Resultado: " << result << std::endl;
    return 0;
}