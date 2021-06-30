
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

int dinamic(vector<int> V, vector<int> P, int W) {
  int n = V.size();
  int vec[n + 1][W + 1];

  for (int w = 0; w <= W; w++) {
    vec[0][w] = 0;
  }
  for (int i = 0; i <= n; i++) {
    vec[i][0] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int w = 1; w <= W; w++) {

      if (P[i - 1] <= w) {
        vec[i][w] = max(V[i - 1] + vec[i - 1][w - P[i - 1]], vec[i - 1][w]);
        // if (V[i - 1] + vec[i - 1][w - P[i - 1]] > vec[i - 1][w]) {
        //   vec[i][w] = V[i - 1] + vec[i - 1][w - P[i - 1]];
        // } else {
        //   vec[i][w] = vec[i - 1][w];
        // }

      } else {
        vec[i][w] = vec[i - 1][w];
      }
    }
  }
  return vec[n][W];
}

int main() {
  vector<int> V = {3, 5, 8, 4, 10, 12};
  vector<int> P = {2, 4, 5, 3, 9, 9};
  int W = 20;

  int f = dinamic(V, P, W);
  cout << f << endl;
  return 0;
}
