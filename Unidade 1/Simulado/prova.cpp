/**!
 *  Program usado na avaliação de LP1, 2017.1
 *  @date 11 de abrill de 2017
 */

#include <iostream>  // cout, endl
#include <iomanip>   // setw
#include <iterator>  // distance
#include <cstdlib>   // memset, memcmp, memcpy
#include <cassert>   // assert()
#include <cstring>



// ================================================================================

namespace prova
{
    // Tipos basicos utiizados pelas funções.
    using byte = unsigned char;
    using Compare = int(const void*, const void*);
    using UnaryPredicate = bool(const void*);

    // Questão 1
    bool eh_particionada( const void * first, const void * last, size_t size,
            UnaryPredicate *p )
    {
        byte *f = (byte *) first;
        byte *l = (byte *) last;
        bool final = false;
        while(f != l) {
            if(!p(f)) {
                final = true;
            } else if(p(f) && final) {
                return false;
            }
            f += size;
        }
        return true; // stub, substituir por seu código
    }

    // Questão 2-a
    const void * limite_inferior( const void *first, const void *last,
            size_t size, const void * value, Compare *cmp )
    {
        byte *f = (byte *) first;
        byte *l = (byte *) last;
        while(f != l) {
            if(cmp(f, value) >= 0) {
                return f;
            }
            f += size;
        }
        return last;
    }

    // Questão 2-b
    const void * limite_superior( const void *first, const void *last,
            size_t size, const void * value, Compare *cmp )
    {
        byte *f = (byte *) first;
        byte *l = (byte *) last;
        while(f != l) {
            if(cmp(f, value) > 0) {
                return f;
            }
            f += size;
        }
        return last; // stub, substituir por seu código
    }

    // Questão 3
    void * remove( const void *first, const void *last, const void *first_r,
               const void *last_r, size_t size )
    {
        byte *f  = (byte *) first;
        byte *l  = (byte *) last;
        byte *fr = (byte *) first_r;
        byte *lr = (byte *) last_r;
        while(f != l && fr != lr) {
            if(memcmp(f, fr, size) == 0) {
                for(byte *i = f; i != l; i += size) {
                    byte *temp = new byte(size);
                    memcpy(temp, i, size);
                    memcpy(i, i + size, size);
                    memcpy(i + size, temp, size);
                }
                l -= size;
                fr += size;
            }
            f += size;
        }
        return l;
    }

    // Questão 4
    bool contem( const void *first1, const void *last1, const void *first2,
            const void *last2, size_t size, Compare *cmp )
    {
        byte *f1 = (byte *) first1;
        byte *l1 = (byte *) last1;
        byte *f2 = (byte *) first2;
        byte *l2 = (byte *) last2;
        bool comecou    = false;
        while(f1 != l1) {
            if(comecou) {
                f1 += size;
                f2 += size;
                if(f2 == l2) {
                    return true;
                }
                if(cmp(f1, f2) != 0) {
                    return false;
                }
                continue;
            }
            if(cmp(f1, f2) == 0) {
                comecou = true;
            } else {
                f1 += size;   
            }
        }
        return false; // stub, substituir por seu código
    }

    // Questão 5
    void * remove_repetidos( const void *first, const void *last, const void *value,
            size_t size, Compare *cmp )
    {
        byte *f  = (byte *) first;
        byte *l  = (byte *) last;
        byte *nl = (byte *) first;
        while(f != l) {
            if(cmp(f, value) != 0) {
                std::memcpy(nl, f, size);
                nl += size;
            }
            f += size;
        }
        return nl;
    }
} // namespace prova


// ================================================================================
// CLIENT CODE
// ================================================================================

bool eh_impar( const void *a )
{
    int *aa = (int *) a;
    return *aa % 2 != 0;
}

bool acima_20( const void *a )
{
    int *aa = (int *) a;
    return *aa > 20;
}

int compare_ints( const void * a, const void * b )
{
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



int main( )
{
    size_t score = 0;
    size_t total = 100; // Pontos das 2 primeiras questões.
    std::cout << ">>> Voce inicia a prova com " << score << " pontos (de " << total << ").\n\n";

    // ================================================================================
    // Questao 1 - teste: vetor está particionado
    // ================================================================================
    {
        std::cout << ">>> Q1-a: testando a funcao eh_particionada()\n";

        int A[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

        // Verificando se o vetor estah particionado com os impares na frente dos pares.
        auto result = prova::eh_particionada( std::begin(A), std::end(A), sizeof(int), eh_impar );
        if ( result == false )
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
        else
        {
            score += 10;
            std::cout << "    Sua resposta estah correta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

    // ================================================================================
    // Questao 1 - teste:  vetor NÃO está particionado
    // ================================================================================
    {
        std::cout << ">>> Q1-b: testando a funcao eh_particionada()\n";

        int A[] = { 21, 41, 54, 38, 6, 5, 21, 4, 1, -3 };

        // Verificando se o vetor estah particionado com os valores acima de 20 na frente.
        auto result = prova::eh_particionada( std::begin(A), std::end(A), sizeof(int), acima_20 );

        if ( result == true )
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
        else
        {
            score += 10;
            std::cout << "    Sua resposta estah correta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

    // ================================================================================
    // Questao 2
    // ================================================================================
    {
        std::cout << ">>> Q2-a: testando a funcao limite_inferior(): limite inferior no meio\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
        auto target(4);

        // buscando o limite inferior
        auto li = (int *) prova::limite_inferior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( *li == 4 and std::distance(std::begin(A), li) == 7 )
        {
            score += 5;
            std::cout << "    Sua resposta estah correta!\n";
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-b: testando a funcao limite_inferior(): valor ausente mas limite inferior no intervalo\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 5, 5, 6 };
        auto target(4);

        // buscando o limite inferior
        auto li = (int *) prova::limite_inferior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( *li == 5 and std::distance(std::begin(A), li) == 10)
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-c: testando a funcao limite_inferior(): limite inferior fora do intervalo\n";

        int A[] = { 1, 1, 2, 3, 3, 3 };
        auto target(5);

        // buscando o limite inferior
        auto li = (int *) prova::limite_inferior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( li == std::end(A) )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-d: testando a funcao limite_inferior(): limite inferior no inicio\n";

        int A[] = { 1, 1, 2, 3, 3, 3 };
        auto target(1);

        // buscando o limite inferior
        auto li = (int *) prova::limite_inferior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( li == std::begin(A) )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-e: testando a funcao limite_superior(): valor presente, limite inferior no meio do vetror.\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
        auto target(4);

        // buscando o limite inferior
        auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( *li == 5 and std::distance(std::begin(A), li) == 10 )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-f: testando a funcao limite_superior(): valor ausente, limite superior presente.\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 5, 5, 6 };
        auto target(4);

        // buscando o limite inferior
        auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( *li == 5 and std::distance(std::begin(A), li) == 7 )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-g: testando a funcao limite_superior(): valor ausente, limite superior fora do intervalo.\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 5, 5, 6 };
        auto target(7);

        // buscando o limite inferior
        auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( li == std::end(A) )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-h: testando a funcao limite_superior(): valor no inicio\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 5, 5, 6 };
        auto target(1);

        // buscando o limite inferior
        auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( *li == 2 and std::distance( std::begin(A), li ) == 2 )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

    {
        std::cout << ">>> Q2-i: testando a funcao limite_superior(): valor menor que início do intervalo.\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 5, 5, 6 };
        auto target(0);

        // buscando o limite inferior
        auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( *li == 1 and li == std::begin(A) )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

    // ================================================================================
    // TODO: Inclua aqui seus testes para as questões 3, 4 e 5.
    // ================================================================================

    {
        std::cout << ">>> Q3-a: testando a funcao remove():\n";

        int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        // removendo elementos
        int *result = (int *) prova::remove(std::begin(A), std::end(A), std::begin(A) + 2, std::begin(A) + 5, sizeof(A[0]));

        if ( result == std::begin(A) + 7)
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

    {
        std::cout << ">>> Q4-a: testando a funcao contem():\n";

        int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        // removendo elementos
        bool result = prova::contem(std::begin(A), std::end(A), std::begin(A) + 2, std::begin(A) + 5, sizeof(A[0]), compare_ints);

        if (result)
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 10;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

    {
        std::cout << ">>> Q4-b: testando a funcao contem(): não contem\n";

        int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int B[] = {2, 3, 4, 7};

        // removendo elementos
        bool result = prova::contem(std::begin(A), std::end(A), std::begin(B), std::end(B), sizeof(A[0]), compare_ints);

        if (!result)
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 10;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

    {
        std::cout << ">>> Q5-a: testando a funcao remove_repetidos():\n";

        int A[] = {1, 2, 3, 4, 7, 7, 7, 8, 9, 10};
        int value = 7;

        // removendo elementos
        int *result = (int *) prova::remove_repetidos(std::begin(A), std::end(A), &value, sizeof(A[0]), compare_ints);

        if (result == std::begin(A) + 7)
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 10;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    std::cout << "\n\n>>> Normal exiting...\n";

    return EXIT_SUCCESS;

}
