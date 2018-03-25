#include <iostream>

int gcd(int x, int y) {
    if(y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
    std::cout << gcd(10, 3) << std::endl;;
    return 0;
}