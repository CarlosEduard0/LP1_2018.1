/*
    Professor, essa é um resposta opcional baseada em outra forma de interpretação do problema.
    De acordo com o que foi formulado na pergunta, o aluno poderia entender o problema de modo
    que a saída não seria conforme o senhor expôs no enunciado.
    Uma possível interpretação que é perfeitamente plausível seria a de verificar a maior diferença
    entre as alturas de uma montanha e a da seguinte(tanto da ída como na volta), tendo assim uma carga mínima para
    VTNT percorrer todo o seu trajeto sem correr o risco de ficar sem bateria. 
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
        int maior = 0;
        for(unsigned j = 0; j < ints.at(i).size() - 1; j++) {
            if(ints.at(i).at(j + 1) - ints.at(i).at(j) > maior) {
                maior = ints.at(i).at(j + 1) - ints.at(i).at(j);
            }
            if(ints.at(i).at(j) - ints.at(i).at(j + 1) > maior) {
                maior = ints.at(i).at(j) - ints.at(i).at(j + 1);
            }
        }
        saida << maior << std::endl;
    }

    /* Fecha stream para os arquivos de entrada e saída */
    arquivo.close();
    saida.close();
    return 0;
}