#include <iostream>

//Quantidade de números que serão inseridos e o tamanho do vetor de números
const int TAMANHO = 20;

int main(void) {

    //Declaração de variáveis
    int posMenorElemento;
    float numeros[TAMANHO], menorElemento;

    //Entrada de dados
    for(int i = 0; i < TAMANHO; i++) {
        std::cin >> numeros[i];
    }

    //Inicializa variáveis com a primeira posição do vetor
    menorElemento       = numeros[0];
    posMenorElemento    = 0;

    //Imprime os elementos do vetor e encontra a posição e o valor do menor elemento
    for(int i = 0; i < TAMANHO; i++) {
        std::cout << ">>> [" << i << "] = " << numeros[i] << std::endl;
        if(numeros[i] < menorElemento) {
            menorElemento       = numeros[i];
            posMenorElemento    =  i;
        }
    }

    //Imprime a posição e o valor da menor elemento encontrado
    std::cout << ">>> Menor elemento: Posição: " << posMenorElemento << " Valor: " << menorElemento << std::endl;

    return 0;
}