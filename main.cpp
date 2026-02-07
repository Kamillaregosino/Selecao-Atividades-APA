#include <iostream>
#include <algorithm>
using namespace std;

struct Activity
{
   int start, end;
};

bool comp(Activity act1, Activity act2)
{
   return (act1.end < act2.end);
}

void maxActivity(Activity act[], int n)
{
   sort(act, act + n, comp);
   cout << "Selected Activities are: " << endl;
   int i = 0, count = 1;
   cout << "Atividade " << i << "-> Início: " << act[i].start
        << " Fim: " << act[i].end << endl;
   for (int j = 1; j < n; j++)
   {
      if (act[j].start >= act[i].end)
      {
         cout << "Atividade " << j << "-> Início: " << act[j].start
              << " Fim: " << act[j].end << endl;
         i = j;
         count++;
      }
   }
   cout << "Total de Atividades Selecionadas: " << count << endl;
}
int main()
{
   Activity actArr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
   int n = 6;
   cout << "Atividades com seus tempos de início e término: " << endl;
   for (int i = 0; i < n; i++)
   {
      cout << "Atividade " << i << "-> Início: " << actArr[i].start
           << " Fim: " << actArr[i].end << endl;
   }
   maxActivity(actArr, n);
   return 0;
}