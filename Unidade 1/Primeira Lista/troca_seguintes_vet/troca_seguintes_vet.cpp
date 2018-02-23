#include <iostream>

//Tamanho do vetor
int const TAMANHO = 20;

void imprimirVetor(int vetor[TAMANHO]);

int main(void) {

    //Declaração de variáveis
    int b[TAMANHO], aux;

    //Preenche o vetor com os dados fornecidos
    for(int i = 0; i < TAMANHO; i++) {
        std::cin >> b[i];
    }

    //Imprime o vetor original
    imprimirVetor(b);

    //Troca o conteúdo dos elementos de B de ordem ı́mpar com os de ordem par imediatamente seguintes
    for(int i = 0; i < TAMANHO - 1; i += 2) {
        aux         = b[i];
        b[i]        = b[i + 1];
        b[i + 1]    = aux;
    }

    //Imprime o vetor modificado
    imprimirVetor(b);

    return 0;
}

//Imprime o vetor passado como parâmetro
void imprimirVetor(int vetor[TAMANHO]) {
    std::cout << "[";
    for(int i = 0; i < TAMANHO; i++) {
        std::cout << vetor[i] << ", ";
    }
    std::cout << "]" << std::endl;
}