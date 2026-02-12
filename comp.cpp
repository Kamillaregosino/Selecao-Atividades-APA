#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <fstream> 
#include <cmath>

using namespace std;
using namespace std::chrono;

struct Atividade {
    int inicio, fim;
};

// Função de comparação para ordenar as atividades pelo tempo de término
bool compararAtividades(Atividade ato1, Atividade ato2) {
    return (ato1.fim < ato2.fim);
}

void selecaoAtividadesSilenciosa(vector<Atividade>& atividades) {
    sort(atividades.begin(), atividades.end(), compararAtividades);
    int i = 0;
    for (int j = 1; j < (int)atividades.size(); j++) {
        if (atividades[j].inicio >= atividades[i].fim) {
            i = j;
        }
    }
}

int main() {
    vector<int> tamanhos = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    
    ofstream arquivo("Data/resultados_complexidade.csv");

    if (!arquivo.is_open()) {
        cout << "Erro: A pasta 'Data' nao existe ou o arquivo nao pode ser criado!" << endl;
        return 1;
    }

    // Cabeçalho do CSV
    arquivo << "N,Tempo_Microsegundos,Teoria_NlogN" << endl;

    cout << "Iniciando testes e salvando em Data/resultados_complexidade.csv..." << endl;

    for (int n : tamanhos) {
        vector<Atividade> listaAtividades(n);
        for (int i = 0; i < n; i++) {
            listaAtividades[i].inicio = rand() % n;
            listaAtividades[i].fim = listaAtividades[i].inicio + (rand() % 20 + 1);
        }

        auto inicioTempo = high_resolution_clock::now();
        selecaoAtividadesSilenciosa(listaAtividades);
        auto fimTempo = high_resolution_clock::now();

        auto duracao = duration_cast<microseconds>(fimTempo - inicioTempo);
        double valorTeorico = n * log2(n);

        // Escrevendo no arquivo CSV
        arquivo << n << "," << duracao.count() << "," << valorTeorico << endl;
        
        cout << "Concluido N = " << n << endl;
    }

    arquivo.close();
    cout << "\nArquivo salvo com sucesso!" << endl;

    return 0;
}