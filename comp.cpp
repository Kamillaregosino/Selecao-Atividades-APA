#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <fstream> 
#include <cmath>

using namespace std;
using namespace std::chrono;

struct Activity {
    int start, end;
};

bool comp(Activity act1, Activity act2) {
    return (act1.end < act2.end);
}

void maxActivitySilent(vector<Activity>& act) {
    sort(act.begin(), act.end(), comp);
    int i = 0;
    for (int j = 1; j < (int)act.size(); j++) {
        if (act[j].start >= act[i].end) {
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
        vector<Activity> actArr(n);
        for (int i = 0; i < n; i++) {
            actArr[i].start = rand() % n;
            actArr[i].end = actArr[i].start + (rand() % 20 + 1);
        }

        auto start = high_resolution_clock::now();
        maxActivitySilent(actArr);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        double teoria = n * log2(n);

        // Escrevendo no arquivo CSV
        arquivo << n << "," << duration.count() << "," << teoria << endl;
        
        cout << "Concluido N = " << n << endl;
    }

    arquivo.close();
    cout << "\nArquivo salvo com sucesso!" << endl;

    return 0;
}