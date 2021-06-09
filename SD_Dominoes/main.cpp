#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, i = 0, j = 0;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int secv = k;
    int adaug;
    for(i = 0; i < n; ++i)
    {
        while(j < n and a[j] - a[i] - (j - i) <= k)
            j++;
        adaug = a[j] - a[i] - (j - i);
        if(secv < a[j] - a[i] + (k - adaug))
            secv = a[j] - a[i] + (k - adaug);
    }
    cout << secv;
    return 0;
}
