/*
    Professor, esse algorítmo foi feito conforme os exemplos de entradas e suas respectivas saídas que o senhor apresentou
    no enunciado da questão, já o algoritmo vtnt2.cpp foi escrito como outro forma de interpretação do problema.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>

int main() {
    /* Abre stream para os arquivos de entrada e saída */
    std::ifstream arquivo("dados.txt");
    std::ofstream saida("saida.txt");
    
    /* Lê todos os dados do arquivo de entrada e armazena em uma matriz de vectors */
    std::string line;
    std::vector<std::vector<int>> ints;
    while(getline(arquivo, line)) {
        std::istringstream is(line);
        ints.push_back(std::vector<int>(std::istream_iterator<int>(is), std::istream_iterator<int>()));
    }

    /* Realiza o processamento dos dados e imprime na saída o resuldo */
    for(unsigned int i = 0; i < ints.size(); i++) {
        int maior = ints.at(i).at(0);
        int menor = ints.at(i).at(0);
        for(unsigned j = 0; j < ints.at(i).size(); j++) {
            if(ints.at(i).at(j) > maior) {
                maior = ints.at(i).at(j);
            }
            if(ints.at(i).at(j) < menor) {
                menor = ints.at(i).at(j);
            }
        }
        saida << maior - menor << std::endl;
    }

    /* Fecha stream para os arquivos de entrada e saída */
    arquivo.close();
    saida.close();
    return 0;
}