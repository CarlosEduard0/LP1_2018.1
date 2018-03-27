#include <iostream>

int pascal(int linha, int coluna) {
    if(linha == coluna || coluna == 0) {
        return 1;
    }
    return pascal(linha - 1, coluna - 1) + pascal(linha - 1, coluna);
}

void print_triangle(int height) {
    for(int i = 0; i <= height; i++) {
        for(int j = 0; j <= i; j++) {
            std::cout << pascal(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

int main () {
    print_triangle(10);
    return 0;
}