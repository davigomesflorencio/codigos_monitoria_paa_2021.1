#include <bits/stdc++.h>
#include <iostream>
#include <stack>

#define MAX_VALUE 1e9
using namespace std;

int DivideConquistIndexX(vector<int> V) {
  int inicio = 1;
  int fim = V.size();

  while (inicio < fim) {
    int meio = inicio + (fim - inicio) / 2;
    if (V[meio] == meio) {
      return meio;
    } else if (V[meio] < meio) {
      inicio = meio + 1;
    } else {
      fim = meio - 1;
    }
  }
  return -1;
}

int main() {
  vector<int> V = {1, 2, 2, 5, 6, 6, 6};
  // sort(V.begin(),V.end());
  // int X=50;

  int f = DivideConquistIndexX(V);
  cout << f << endl;
  return 0;
}