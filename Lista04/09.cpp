#include <bits/stdc++.h>

using namespace std;

typedef pair<int, float> pi;

struct greaters
{
    bool operator()(const pi &a, const pi &b) const
    {
        return a.second > b.second;
    }
};

vector<int> licencasgreedy(vector<pi>& P)
{

    sort(P.begin(), P.end(),greaters());

    for (int i = 0; i < P.size(); i++)
    {
        cout << P[i].first <<" , "<<P[i].second<< " \n";
    }
    vector<int> res;
    for (int i = 0; i < P.size(); i++)
    {
        res.push_back(P[i].first);
    }

    return res;
}

int main()
{
    vector<pi> P;
    P.push_back(make_pair(1, 1.001));
    P.push_back(make_pair(2, 1.12));
    P.push_back(make_pair(3, 1.01));

    vector<int> res = licencasgreedy(P);
    for (auto x : res)
    {
        cout << x << " ";
    }
    return 0;
}
