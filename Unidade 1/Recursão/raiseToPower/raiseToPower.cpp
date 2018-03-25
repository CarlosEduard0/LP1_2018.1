#include <iostream>

int raiseToPower(int n, int k) {
    if(k == 0) {
        return 1;
    }
    return n * raiseToPower(n, k - 1);
}

int main() {
    std::cout << raiseToPower(2, 4) << std::endl;
    return 0;
}