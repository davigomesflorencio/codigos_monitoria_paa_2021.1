
#include <bits/stdc++.h>
#include <iostream>
#include <stack>

#define MAX_VALUE 1e9 
using namespace std;

int bruteforce(vector<int> V , int X){
  if (X == 0) {
    return 0;  
  }
  int aux = MAX_VALUE;
	for(int i=0;i < V.size();i++){
		if(V[i]<=X){
			aux = min(aux,1 + bruteforce(V,X-V[i]));
		}
	}
	return aux;
}

int main(int argc, char const *argv[]) {
  vector<int> V = {50, 20, 20, 2, 10 ,10,10,10,5};
  int X=45;
  
  int f =bruteforce(V,X); 
  cout<< f<<endl; 	
  return 0;
}
