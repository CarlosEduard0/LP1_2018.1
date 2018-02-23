#include <iostream>

int main(void) {

    //Declaração de variáveis
    int x, totNumeros = 0;
    /**
     * [0] [0,25)
     * [1] [25,50)
     * [2] [50,75)
     * [3] [75,100)
     */
    int intervalos[4] = {0, 0, 0, 0,};

    std::cout << "Entre com valores inteiros (Ctrl+d p/ encerrar): " << std::endl;

    //Recebe o valor e verifica em qual intervalo ele faz parte
    while(std::cin >> x) {
        if(x >= 0 && x < 25) {
            intervalos[0]++;
        } else if(x >= 25 && x < 50) {
            intervalos[1]++;
        } else if(x >= 50 && x < 75) {
            intervalos[2]++;
        } else if(x >= 75 && x < 100) {
            intervalos[3]++;
        }
        totNumeros++;
    }

    //Imprime resultado do processamento em porcentagem
    std::cout << ">>> [0,25) > " << ((float) intervalos[0] / totNumeros) * 100 << "%" << std::endl;
    std::cout << ">>> [25,50) > " << ((float) intervalos[1] / totNumeros) * 100 << "%" << std::endl;
    std::cout << ">>> [50,75) > " << ((float) intervalos[2] / totNumeros) * 100 << "%" << std::endl;
    std::cout << ">>> [75,100) > " << ((float) intervalos[3] / totNumeros) * 100 << "%" << std::endl;

    return 0;
}