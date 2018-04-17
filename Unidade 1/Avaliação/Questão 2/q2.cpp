#include <iostream>
#include <vector>

using UnaryPredicate = bool(const int *);

/* Função para selecionar os elementos baseado no predicado passado como parâmetro */
std::pair<int *, int *> array_selected(const int *first, const int *last, UnaryPredicate *p) {
    std::vector<int> *ints = new std::vector<int>();
    while(first != last) {
        if(p(first)) {
            ints->push_back(*first);
        }
        first++;
    }
    return std::make_pair(&*ints->begin(), &*ints->end());
}

/* Predicado simples */
bool pred(const int *a) {
    return *a < 5;
}

/* Função main onde os testes são realizados */
int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::pair<int *, int *> par = array_selected(std::begin(A), std::end(A), pred);
    for(int *i = par.first; i != par.second; i++) {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
    return 0;
}