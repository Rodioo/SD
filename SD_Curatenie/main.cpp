#include <bits/stdc++.h>

using namespace std;

ifstream in("curatenie.in");
ofstream out("curatenie.out");

int n;
int nr, inorder[500001], preorder[500001], leftTree[500001], rightTree[500001];

void construct(int idx, int start, int sfarsit)
{
    int poz = inorder[idx];
    if(poz > start)
    {
        nr++;
        leftTree[idx] = preorder[nr];
        construct(leftTree[idx], start, poz - 1);
    }
    if(poz < sfarsit)
    {
        nr++;
        rightTree[idx] = preorder[nr];
        construct(rightTree[idx], poz + 1, sfarsit);
    }
}
int main()
{
    in >> n;
    int aux;
    for(int i = 1; i <= n; ++i)
    {
        in >> aux;
        inorder[aux] = i;
    }
    for(int i = 1; i <= n; ++i)
        in >> preorder[i];

    construct(preorder[1], 1, n);

    for(int i = 1; i <= n; ++i)
        out << leftTree[i] << " " << rightTree[i] << "\n";
    return 0;
}
