#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node *l, *r;
};

node* newNode(int x)
{
    node* aux = new node;
    aux->val = x;
    aux->l = aux->r = NULL;
    return aux;
}

void preorder(node* rad)
{
    if(rad != NULL)
    {
        cout << rad->val << " ";
        preorder(rad->l);
        preorder(rad->r);
    }
}

vector <node*> build(int start, int sfarsit)
{
    vector <node*> ans;
    if(start > sfarsit)
    {
        ans.push_back(NULL);
        return ans;
    }
    for(int i = start; i <= sfarsit; ++i)
    {
        vector <node*> stanga = build(start, i - 1);
        vector <node*> dreapta = build(i + 1, sfarsit);
        for(int j = 0; j < stanga.size(); ++j)
        {
            node* auxS = stanga[j];
            for(int k = 0; k < dreapta.size(); ++k)
            {
                node* auxD = dreapta[k];
                node* nod = newNode(i);
                nod->l = auxS;
                nod->r = auxD;
                ans.push_back(nod);
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector <node*> ans = build(1, n);
    for(auto nod : ans)
    {
        preorder(nod);
        cout << "\n";
    }

    return 0;
}
