#include <iostream>

//Quantidade de números que serão informados e o tamanho do vetor
int const TAMANHO = 20;

//Imprime o vetor recebido por parâmetro
void imprimeVetor(int vetor[TAMANHO]);
//Inverte o vetor recebido por parâmetro
void inverterVetor(int vetor[TAMANHO]);

int main(void) {

    //Vetor onde serão armazenados os números digitados pelo usuário
    int a[TAMANHO];

    //Preenche o vetor com os números informados
    for(int i = 0; i < TAMANHO; i++) {
        std::cin >> a[i];
    }

    //Imprime o vetor antes de inverter
    imprimeVetor(a);
    //Inverte o vetor
    inverterVetor(a);
    //Imprime o vetor depois de inverter
    imprimeVetor(a);

    return 0;
}

//Imprime o vetor recebido por parâmetro
void imprimeVetor(int vetor[TAMANHO]) {
    std::cout << "[";
    for(int i = 0; i < TAMANHO; i++) {
        std::cout << vetor[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

//Inverte o vetor recebido por parâmetro
void inverterVetor(int vetor[TAMANHO]) {
    int temp;
    for(int i = 0; i < TAMANHO / 2; i++) {
        temp                    = vetor[i];
        vetor[i]                = vetor[TAMANHO - 1 - i];
        vetor[TAMANHO - 1 - i]  = temp;
    }
}