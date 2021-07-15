#include <bits/stdc++.h>

using namespace std;

typedef pair<vector<int>,vector<int>> pi;

struct greaters
{
    bool operator()(const int &a, const int &b) const
    {
        return a < b;
    }
};

pi particao(vector<int> &P)
{

    sort(P.begin(), P.end(), greaters());

    // Esse for não é analisado na complexidade
    for (int i = 0; i < P.size(); i++)
    {
        cout << P[i] << " ";
    }
    cout << endl;

    int mid=P.size() / 2;
    int end=P.size()-1;

    vector<int> res1;
    vector<int> res2;

    for (int i = 0; i < mid;i++)
    {
        res1.push_back(P[end-i]); 
        res2.push_back(P[i]);
    }


    return make_pair(res1,res2);
}

int main()
{
    vector<int> P = {4, 2, 1, 3, 5, 1, 1, 1};

    pi res = particao(P);
    
    vector<int> res1= res.first;
    vector<int> res2 = res.second;

    for (auto x: res1){
        cout<< x<<" ";
    }
    cout<<"\n"<<endl;
    
    for (auto x: res2){
        cout<< x<<" ";
    }
    
    cout<<"\n"<<endl;
    
    return 0;
}
