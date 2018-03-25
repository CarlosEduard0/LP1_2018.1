#include <iostream>

int cannonball(int n) {
    if(n == 1) {
        return 1;
    }
    return n * n + cannonball(n - 1);
}

int main() {
    std::cout << cannonball(4) << std::endl;
    return 0;
}