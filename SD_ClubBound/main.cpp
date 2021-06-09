#include <bits/stdc++.h>

using namespace std;

void sort(vector<int>& v, int M)
{
    if(M == 0)
        return;
    priority_queue <int, vector<int>, greater<int> > heap;
    vector <int> ans;
    for(int i = 0; i <= M; ++i)
        heap.push(v[i]);
    for(int i = M + 1; i < v.size(); ++i)
    {
        ans.push_back(heap.top());
        heap.pop();
        heap.push(v[i]);
    }
    while(!heap.empty())
    {
        ans.push_back(heap.top());
        heap.pop();
    }
    v = ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> v;
    int aux;
    for(int i = 0; i < n; ++i)
    {
        cin >> aux;
        v.push_back(aux);
    }
    sort(v, m);
    for(int nr : v)
        cout << nr << " ";
    return 0;
}
