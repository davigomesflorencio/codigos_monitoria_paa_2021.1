
#include <bits/stdc++.h>
#include <iostream>
#include <stack>

#define MAX_VALUE 1e9
using namespace std;

int bruteforce(vector<int> V, int X) {
  if (X == 0) {
    return 0;
  }
  int aux = MAX_VALUE;
  for (int i = 0; i < V.size(); i++) {
    if (V[i] <= X) {
      vector<int> ut = V;
      ut.erase(ut.begin() + i);
      aux = min(aux, 1 + bruteforce(ut, X - V[i]));
    }
  }
  return aux;
}

bool dinamic(vector<int> V, int X) {
  if (X == 0) {
    return 0;
  }
  // Caso base
  vector<int> vec(X + 1);
  
  vec[0] = 1;

  for (int i = 0; i < V.size(); i++) {
    for (int j = 0; j < vec.size(); j++) {
      if (V[i] <= j) {
        vec[j] += vec[j - V[i]];
      }
    }
  }

  if (vec[X] != 0) {
    cout << "Consegui" << endl;
    return true;
  }
  return false;
}

int main() {
  vector<int> V = {50, 20, 5, 2};
  int X = 49;

  bool f = dinamic(V, X);
  cout << f << endl;
  return 0;
}
