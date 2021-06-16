
#include <bits/stdc++.h>
#include <iostream>
#include <stack>

#define MAX_VALUE 1e9
using namespace std;

int DivideConquistIndexX(vector<int> V, int X) {
  int inicio = 1;
  int fim = V.size();
  int pivo = inicio + (fim - inicio) / 2;
  int meio1 = inicio + (pivo - inicio) / 2;
  int meio2 = pivo + (fim - pivo) / 2;
  cout << " pivo " << pivo << endl;
  cout << " meio1 " << meio1 << endl;
  cout << " meio2 " << meio2 << endl;

  while (inicio < meio1) {
    int m1 = inicio + (meio1 - inicio) / 2;
    if (V[m1] == X) {
      return m1;
    } else if (V[m1] < X) {
      inicio = m1 + 1;
    } else {
      meio1 = m1 - 1;
      cout << "foi mudado" << endl;
    }
  }
  cout << "VALOR " << meio1 << endl;
  return -1;
}

int main(int argc, const char **argv) {
  vector<int> V = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  //   sort(V.begin(), V.end());
  int X = 1;

  // int f =BruteForceIndexX(V,X);
  // cout<< f<<endl;
  int f = DivideConquistIndexX(V, X);
  cout << f << endl;
  return 0;
}