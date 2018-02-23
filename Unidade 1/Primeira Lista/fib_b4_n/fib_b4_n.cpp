#include <iostream>

void fibonacci(int limite);

int main(void) {
    //Declaração de variáveis
    int n;

    //Recebe o limite da sequência de fibonacci
    std::cin >> n;

    //Imprime a sequência de fibonacci até o limite n
    fibonacci(n);

    return 0;
}

void fibonacci(int limite) {
    int primeiro = 0, segundo = 1, fib;
    if(limite == 1) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << "0 1 ";
        fib = primeiro + segundo;
        while(fib < limite) {
            std::cout << fib << " ";
            primeiro    = segundo;
            segundo     = fib;
            fib         = primeiro + segundo;
        }
        std::cout << std::endl;
    }
}