#include <bits/stdc++.h>
#include <iostream>
#include <stack>

#define MAX_VALUE 1e9
using namespace std;

int DivideConquistIndexX(vector<int> V, int r) {
  int inicio = 0;
  int fim = V.size() - 1;
  int meio = 0;

  while (inicio < fim) {
    meio = inicio + (fim - inicio) / 2;
    // cout << "elem" << V[meio] << endl;
    if (V[meio] - V[inicio] == r * (meio - inicio)) {
      inicio = meio + 1;
    } else if (V[fim] - V[meio] == r * (fim - meio)) {
      //   cout << "meio " << V[meio] << endl;
      fim = meio - 1;
      //   return meio;
    }
  }
  //   cout << "meio final" << meio << endl;
  return V[0] + r * meio;
}

int main() {
  vector<int> V = {1, 4, 10, 13, 16};
  int r = 3;
  //   vector<int> V2 = {2, 4, 6, 8, 10, 12};
  // sort(V.begin(),V.end());
  // int X=50;

  int f = DivideConquistIndexX(V, r);
  cout << f << endl;
  return 0;
}