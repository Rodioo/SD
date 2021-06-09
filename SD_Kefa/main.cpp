#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d, m, f;
    long long ans = 0;
    vector <pair<int, int>> v;
    cin >> n >> d;
    for(int i = 0; i < n; ++i)
    {
        cin >> m >> f;
        v.push_back({m, f});
    }
    sort(v.begin(), v.end());
    int start = 0, sfarsit = 0;
    long long suma = 0;
    while(sfarsit < n)
    {
        while(sfarsit < n and v[sfarsit].first - v[start].first < d)
        {
            suma += v[sfarsit].second;
            sfarsit++;
        }
        ans = max(ans, suma);
        suma -= v[start].second;
        start++;
    }
    cout << ans;
    return 0;
}
