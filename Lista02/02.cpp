
#include <bits/stdc++.h>
#include <iostream>
#include <stack>

#define MAX_VALUE 1e9 
using namespace std;

int bruteforceRecursive(vector<int> V, vector<int> P, int M, int IndexItem) {
    if (M <= 0 || IndexItem >= V.size() || IndexItem < 0)
        return 0;
    int aux1 = 0;
    if (P[IndexItem] <= M)
        aux1 = V[IndexItem] + bruteforceRecursive(V, P, M - P[IndexItem], IndexItem + 1);

    int aux2 = bruteforceRecursive(V, P, M, IndexItem + 1);
    
    return max(aux1, aux2);
}

int BruteForceMochila(vector<int> V, vector<int> P, int M) {
  return bruteforceRecursive(V,P, M, 0);
}


int main(int argc, const char** argv) {
    vector<int> V = {60, 100, 120};
    vector<int> P = {10, 20, 30};
    int M=50;

    int f =BruteForceMochila(V,P,M); 
    cout<< f<<endl; 
    return 0;
}