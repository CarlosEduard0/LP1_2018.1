/* Arquivo de cabeçalho da função bubble_sort personalizada e declaração de alguns tipos necessários */

#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include <iostream>
#include <cstring>

using byte = unsigned char;
using Compare = int(const void *, const void *);
void sort_bubble_2(const void *first, const void *last, size_t size, Compare *cmp);
#endif