#include <bits/stdc++.h>

using namespace std;

ifstream in("planeta.in");
ofstream out("planeta.out");

vector <int> ans;
long long bst[35];

void build(int start, int sfarsit, long long k)
{
    if(sfarsit == 0)
        return;
    int cStart = start;
    while(bst[cStart - start] * bst[sfarsit - cStart] <= k)
    {
        k -= bst[cStart - start] * bst[sfarsit - cStart];
        cStart++;
    }
    ans.push_back(cStart);
    if(start < cStart)
        build(start, cStart - 1, k / bst[sfarsit - cStart]);
    if(sfarsit > cStart)
        build(cStart + 1, sfarsit, k % bst[sfarsit - cStart]);
}

int main()
{
    int n;
    long long k;
    in >> n >> k;
    bst[0] = 1;
    for(int  i = 1; i <= n; ++i)
        bst[i] = 2 * (2 * i - 1) * bst[i - 1] / (i + 1);
    build(1, n, k - 1);
    for(int i = 0; i < ans.size(); i++)
        out << ans[i] << " ";
    return 0;
}
