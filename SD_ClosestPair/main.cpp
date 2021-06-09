#include <bits/stdc++.h>

using namespace std;

int closestPair(vector<int>& first, vector<int>& second)
{
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    int i = 0, j = 0, minim = 100001;
    while(i < first.size() and j < second.size())
    {
        if(abs(first[i] - second[j]) < minim)
            minim = abs(first[i] - second[j]);
        if(first[i] > second[j])
            j++;
        else
            i++;
    }
    return minim;
}

int main()
{
    int n;
    vector <int> v1;
    vector <int> v2;
    cin >> n;
    int aux;
    for(int i = 0; i < n; ++i)
    {
        cin >> aux;
        v1.push_back(aux);
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> aux;
        v2.push_back(aux);
    }
    cout << closestPair(v1, v2);
    return 0;
}
