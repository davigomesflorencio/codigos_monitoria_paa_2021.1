#include <bits/stdc++.h>

using namespace std;

typedef pair<vector<int>, vector<int>> pi;

struct greaters
{
    bool operator()(const int &a, const int &b) const
    {
        return a < b;
    }
};

vector<int> intersection(vector<int> &vec1, vector<int> &vec2)
{

    sort(vec1.begin(), vec1.end(), greaters());
    sort(vec2.begin(), vec2.end(), greaters());

    // Esse for não é analisado na complexidade
    for (auto x : vec1)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : vec2)
    {
        cout << x << " ";
    }
    cout << endl;

    vector<int> res;

    int i = 0;
    int j = 0;
    int n = vec1.size();
    int m = vec2.size();

    while (i < n and j < m)
    {
        if (vec1[i] == vec2[j])
        {
                    
            if (res.size() > 0 and res[res.size() - 1] == vec1[i])
            {
                i += 1;
                j += 1;
            }
            else
            {
                res.push_back(vec1[i]);
                i += 1;
                j += 1;
            }
        }
        else if (vec1[i] < vec2[j])
        {
            i += 1;
        }
        else
        {
            j += 1;
        }
    }
    return res;
}

int main()
{
    vector<int> vec1 = {1, 2, 2, 4, 5, 6, 5, 5};
    vector<int> vec2 = {2, 9, 9, 3, 5, 7};

    vector<int> res1 = intersection(vec1, vec2);
    for (auto x : res1)
    {
        cout << x << " ";
    }
    return 0;
}
