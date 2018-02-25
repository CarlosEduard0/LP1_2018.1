#include <iostream>

using namespace std;

//Capacidade do vetor de números inteiros
const int TAMANHO = 20;

//Assinatura da função de filtragem
int* filter(int *first, int *last);

int main() {

    //Declaração do vetor
    int v[TAMANHO];

    //Preenchimento do vetor
    for(int i = 0; i < TAMANHO; i++) {
        cin >> v[i];
    }

    //Faz a filtragem e recebe a última posição do vetor como ponteiro
    int *last = filter(&v[0], &v[TAMANHO]);

    //Imprime o vetor após a filtragem
    cout << "[";
    for(int *i = &v[0]; i < last; i++) {
        cout << *i << ", ";
    }
    cout << "]" << endl;

    return 0;
}

//Realiza a filtragem do vetor, retornando um ponteiro para a última posição
int* filter(int *first, int *last) {
    int temp, naoPositivos = 0;
    for(; first < last; first++) {
        for(int *i = first; i < last; i++) {
            if(*first <= 0) {
                temp    = *first;
                *first  = *i;
                *i      = temp;
            }
        }
        if(*first <= 0) {
            naoPositivos++;
        }
    }
    return last - naoPositivos;
}