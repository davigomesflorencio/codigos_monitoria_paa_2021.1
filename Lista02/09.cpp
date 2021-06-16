#include <bits/stdc++.h>
#include <iostream>
#include <stack>

#define MAX_VALUE 1e9
using namespace std;

int DivideConquistIndexX(vector<int> V, vector<int> V2) {
  int inicio = 0;
  int fim = V.size() - 1;
  int meio = 0;

  while (inicio <= fim) {
    meio = inicio + (fim - inicio) / 2;
    // cout << "elem" << V[meio] << endl;
    if (V[meio] == V2[meio]) {
      inicio = meio + 1;
    } else if (V[meio] != V2[meio]) {
      //   cout << "meio " << V[meio] << endl;
      fim = meio - 1;
      //   return meio;
    }
  }
  //   cout << "meio final" << meio << endl;
  return inicio;
}

int main() {
  vector<int> V = {2, 3, 4, 6, 8, 10, 12};
  vector<int> V2 = {2, 4, 6, 8, 10, 12};
  // sort(V.begin(),V.end());
  // int X=50;

  int f = DivideConquistIndexX(V, V2);
  cout << f << endl;
  return 0;
}