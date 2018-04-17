#include "bubble_sort.h"

/* Implementação da função bubble_sort personalizada de acordo com os critérios dado pela questão */
void sort_bubble_2(const void *first, const void *last, size_t size, Compare *cmp) {
	byte *f = (byte *) first;
    byte *l = (byte *) last;
    byte *k, *j;
    for(k = f + size; k < l; k += size) {
    	/* O menor elemento “borbulha” para cima, na
           direção do inı́cio do arranjo */
        for(j = l - size; j > f; j -= size) {
            if(cmp(j, j - size) == -1) {
                byte *temp = new byte(size);
                std::memcpy(temp, j, size);
                std::memcpy(j, j - size, size);
                std::memcpy(j - size, temp, size);
            }
        }
        /* o maior elemento “borbulha” para baixo, na direção
           do final do arranjo */
        for(j = f; j < l - size; j += size) {
            if(cmp(j, j + size) == 1) {
                byte *temp = new byte(size);
                std::memcpy(temp, j, size);
                std::memcpy(j, j + size, size);
                std::memcpy(j + size, temp, size);
            }
        }
    }
}