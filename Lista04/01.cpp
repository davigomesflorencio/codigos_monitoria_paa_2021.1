#include <bits/stdc++.h>

using namespace std;

/**

https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

**/


struct greaters{ 
bool operator()(const long& a,const long& b) const{ 
    return a>b; 
} 
}; 

vector<int> kmenores(vector<int>& vec, int k)
{
    vector<int> res;

    make_heap(vec.begin(), vec.end(), greaters());

    for (int i = 0; i < k; i++)
    {
        res.push_back( vec.front());
        vec.pop_back();
        sort_heap (vec.begin(),vec.end());  
    }
    return res;
}

int main()
{
    vector<int> vi = {15, 6, 7, 9, 11, 19};

    int k = 3;

    vector<int> res = kmenores(vi, k);

    for (int i = 0; i < k; i++)
    {
        cout<<res[i]<<" "; 
    }
    return 0;
}
