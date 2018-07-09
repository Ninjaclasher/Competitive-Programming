#include <bits/stdc++.h>

using namespace std;

struct node
{
    vector<int> ind;
    vector<int> fin;
    node* ch[26] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
};

string cur;

void insert(int x, int i, node* &cc)
{
    if (cc == NULL)
        cc = new node;
    if (x == cur.length()-1)
    {
        cc->fin.push_back(i);
        return;
    }
    cc->ind.push_back(i);
    insert(x+1, i, cc->ch[cur[x+1]-'a']);
}

int query(int x, int l, int r, node* cc)
{
    if (cc == NULL)
        return 0;
    int s = (upper_bound(cc->fin.begin(), cc->fin.end(), r)-lower_bound(cc->fin.begin(), cc->fin.end(), l));
    if (x == cur.length()-1)
        return s + (upper_bound(cc->ind.begin(), cc->ind.end(), r)-lower_bound(cc->ind.begin(), cc->ind.end(), l));
    return s + query(x+1, l, r, cc->ch[cur[x+1]-'a']);
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    node* root = new node();
    int n, m, a, b;
    cin>>n>>m;
    for (int x = 1; x <= n; x++)
    {
        cin>>cur;
        insert(0, x, root->ch[cur[0]-'a']);
    }
    while (m--)
    {
        cin>>cur>>a>>b;
        printf("%i\n", query(0, a, b, root->ch[cur[0]-'a']));
    }
}
