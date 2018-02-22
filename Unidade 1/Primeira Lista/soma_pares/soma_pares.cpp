#include <iostream>

int main(void) {

    //Declaração de variáveis
    int m, n;

    //Ler os dados e imprime os resultados
    while(std::cin >> m >> n) {
        int acumulador = 0;
        for(int i = 0; i < n; i++) {
            acumulador += m + i;
        }
        std::cout << acumulador << std::endl;
    }

    return 0;
}