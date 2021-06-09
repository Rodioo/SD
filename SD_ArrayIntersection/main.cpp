#include <bits/stdc++.h>

using namespace std;

vector<int> arrayIntersection(vector<int>& first, vector<int>& second)
{
    unordered_map <int, int> freq1;
    unordered_map <int, int> freq2;
    vector <int> ans;
    for(int i = 0; i < first.size(); ++i)
        freq1[first[i]]++;
    for(int i = 0; i < second.size(); ++i)
        freq2[second[i]]++;
    for(auto it : freq1)
        for(int i = 0; i < min(freq1[it.first], freq2[it.first]); ++i)
            ans.push_back(it.first);
    return ans;
}

int main()
{
    int n1, n2;
    vector <int> v1;
    vector <int> v2;
    cin >> n1 >> n2;
    int aux;
    for(int i = 0; i < n1; ++i)
    {
        cin >> aux;
        v1.push_back(aux);
    }
    for(int i = 0; i < n2; ++i)
    {
        cin >> aux;
        v2.push_back(aux);
    }
    vector <int> ans = arrayIntersection(v1, v2);
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}
