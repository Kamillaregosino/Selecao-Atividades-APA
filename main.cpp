#include <iostream>
#include <algorithm>
using namespace std;

struct Atividade
{
   int inicio, fim;
};

// Função de comparação para ordenar as atividades pelo tempo de término
bool comparar(Atividade ativ1, Atividade ativ2)
{
   return (ativ1.fim < ativ2.fim);
}

void maxAtividades(Atividade listaAtiv[], int n)
{
   sort(listaAtiv, listaAtiv + n, comparar);
   cout << "Atividades Selecionadas são: " << endl;
   
   int i = 0, contador = 1;
   cout << "Atividade " << i << "-> Início: " << listaAtiv[i].inicio
        << " Fim: " << listaAtiv[i].fim << endl;
        
   for (int j = 1; j < n; j++)
   {
      if (listaAtiv[j].inicio >= listaAtiv[i].fim)
      {
         cout << "Atividade " << j << "-> Início: " << listaAtiv[j].inicio
              << " Fim: " << listaAtiv[j].fim << endl;
         i = j;
         contador++;
      }
   }
   cout << "Total de Atividades Selecionadas: " << contador << endl;
}

int main()
{
   // Array de atividades de exemplo
   Atividade arrayAtiv[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
   int n = 6;
   
   cout << "Atividades com seus tempos de início e término: " << endl;
   for (int i = 0; i < n; i++)
   {
      cout << "Atividade " << i << "-> Início: " << arrayAtiv[i].inicio
           << " Fim: " << arrayAtiv[i].fim << endl;
   }
   
   maxAtividades(arrayAtiv, n);
   
   return 0;
}