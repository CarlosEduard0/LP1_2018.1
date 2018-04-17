#include <iostream>
#include "bubble_sort.h"

/* Função de comparação no lado do CLIENTE */
int compare_ints(const void *a, const void *b) {
	int *aa = (int *) a;
	int *bb = (int *) b;
	if(*aa > *bb) {
		return 1;
	} else if(*aa < *bb) {
		return -1;
	} else {
		return 0;
	}
}

/* Função main para realizar os testes */
int main() {
	int A[] = {6, 2, 10, 3, 4, 90, 1};
	sort_bubble_2(std::begin(A), std::end(A), sizeof(int), compare_ints);
	for(int *i = std::begin(A); i != std::end(A); i++) {
		std::cout << *i << ", ";
	}
	std::cout << std::endl;
	return 0;
}