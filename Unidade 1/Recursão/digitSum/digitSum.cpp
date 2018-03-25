#include <iostream>

int digitSum(int n) {
    if(n == 0) {
        return 0;
    }
    return n % 10 + digitSum(n / 10);
}

int main() {
    std::cout << digitSum(1729) << std::endl;
    return 0;
}