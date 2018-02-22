#include <iostream>

const int NUMEROS = 5;

int main(void) {
    //Declaração de variáveis
    int negativos = 0, temp;

    std::cout << "Digite " << NUMEROS << " números inteiros: ";

    //Recebendo os dados do usuário e veirificando se é negativo.
    for(int i = 0; i < NUMEROS; i++) {
        std::cin >> temp;
        if(temp < 0) {
            negativos++;
        }
    }

    //Imprimindo o resultado do processamento
    std::cout << "Números negativos: " << negativos << std::endl;
    return 0;
}