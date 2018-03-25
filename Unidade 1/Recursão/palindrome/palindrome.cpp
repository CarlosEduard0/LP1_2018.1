#include <iostream>

bool palindrome(const std::string &str, int inicio, int fim) {
    if(inicio >= fim) {
        return true;
    }
    if(str[inicio] != str[fim]) {
        return false;
    }
    return palindrome(str, ++inicio, --fim);
}

int main() {
    std::string teste = "level";
    std::cout << palindrome(teste, 0, teste.length() - 1) << std::endl;
    return 0;
}