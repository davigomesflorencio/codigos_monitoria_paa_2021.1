
#include <bits/stdc++.h>
#include <iostream>
#include <stack>

#define MAX_VALUE 1e9 
using namespace std;


int DivideConquistIndexX(vector<int> V, int X) {
    int inicio=1;
    int fim=V.size();

    while(inicio<fim){
        int meio =inicio +(fim-inicio)/2;
        if(V[meio]==X){
            return meio;
        }else if(V[meio]<X){
            inicio=meio+1;
        }else{
            fim=meio-1;
        }
    }
    return -1;
}

int BruteForceIndexX(vector<int> V, int X) {
    int fim=V.size();
    for(int i=0;i<fim;i++){
        if(V[i]==X){
            return i;
        }
    }
    return -1;
}

int main(int argc, const char** argv) {
    vector<int> V = {60, 100, 120};
    sort(V.begin(),V.end());
    int X=50;

    int f =BruteForceIndexX(V,X); 
    cout<< f<<endl; 
    f =DivideConquistIndexX(V,X);
    cout<< f<<endl; 
    return 0;
}