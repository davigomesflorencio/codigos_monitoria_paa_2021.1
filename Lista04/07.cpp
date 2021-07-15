#include <bits/stdc++.h>

using namespace std;



struct greaters
{
    bool operator()(const long &a, const long &b) const
    {
        return a > b;
    }
};

int caiaquistas(vector<int> &P,int k)
{

    sort(P.begin(), P.end(), greaters());

    for (int i = 0; i < P.size(); i++)
    {
        cout << P[i] << " ";
    }
    cout << endl;

    int start = 0;
    int end = P.size() - 1;
    int res = 0;
    for (int i = 0; i < end;)
    {
        if (P[start] + P[end] <= k)
        {
            end--;
            i++;
            start++;
            res = res + 1;
        }
        else
        {
            start++;
            res = res + 1;
        }
    }

    return res;
}

int main()
{
    vector<int> P = {4, 2, 1, 3, 5, 1, 1, 1};

    int k=10;
    int res = caiaquistas(P,k);
    cout << "res " << res << endl;
    return 0;
}
