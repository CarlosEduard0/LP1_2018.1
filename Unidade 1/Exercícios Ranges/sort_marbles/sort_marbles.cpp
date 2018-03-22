#include <iostream>

enum ball_t {B = 0, W = 1};

ball_t* sort_marbles(ball_t *first, ball_t *last) {
    int white = 0;
    while(first != last) {
        ball_t *i = first + 1;
        while(i != last) {
            if(*first > *i) {
                std::swap(*first, *i);
            }
            i++;
        }
        if(*first == W) {
            white++;
        }
        first++;
    }
    return last - white;
}

int main() {
    ball_t vet[] = {W, B, B, W, W, B, W};
    ball_t *last = sort_marbles(std::begin(vet), std::end(vet));
    for(ball_t *i = std::begin(vet); i != last; i++) {
        std::cout << *i << std::endl;
    }
    return 0;
}