#include <bits/stdc++.h>

using namespace std;

struct node
{
    node* ch[2] = {NULL, NULL};
    int val, pr, su;
};

vector<int> arr(100004);
vector<node *> tmp;

node* build(int l, int r)
{   
    node *cur = new node();
    if (l == r)
        cur->val = cur->pr = cur->su = arr[l];
    else
    {
        int m = l+r>>1;
        cur->ch[0] = build(l, m);
        cur->ch[1] = build(m+1, r);
        cur->val = cur->ch[0]->val + cur->ch[1]->val;
        cur->pr = max(cur->ch[0]->pr, cur->ch[0]->val + cur->ch[1]->pr);
        cur->su = max(cur->ch[1]->su, cur->ch[1]->val + cur->ch[0]->su);
    }
    return cur;
}

node *update(int l, int r, int i, int v, node *t)
{
    node *cur = new node(*t);
    if (cur->ch[0] == NULL)
    {
        cur->val = cur->pr = cur->su = v;
        return cur;
    }
    int m = l+r>>1;
    if (i <= m)
        cur->ch[0] = update(l, m, i, v, t->ch[0]);
    else
        cur->ch[1] = update(m+1, r, i, v, t->ch[1]);
    cur->val = cur->ch[0]->val + cur->ch[1]->val;
    cur->pr = max(cur->ch[0]->pr, cur->ch[0]->val + cur->ch[1]->pr);
    cur->su = max(cur->ch[1]->su, cur->ch[1]->val + cur->ch[0]->su);    
    return cur;
}

void query(int l, int r, int s, int e, node* cur)
{
    if (l >= s && r <= e)
    {
        tmp.push_back(cur);
        return;
    }
    int m = l+r>>1;
    if (s <= m) query(l, m, s, e, cur->ch[0]);
    if (m < e) query(m+1, r, s, e, cur->ch[1]);
}

int main()
{
    int n, a, b, q;
    char t;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
        scanf("%i", &arr[x]);
    vector<node*> root;
    root.push_back(build(0, n-1));
    scanf("%i", &q);
    while (q--)
    {
        scanf(" %c%i", &t, &a);
        if (t != 'G') scanf("%i", &b);
        switch(t)
        {
            case 'U':
                --a;
                root.push_back(update(0, n-1, a, b, root.back()));
            break;
            case 'G':
                root.push_back(root[a]);
            break;
            case 'P':
            case 'S':
                --a, --b;
                tmp.clear();
                query(0, n-1, a, b, root.back());
                int ma = 0, s = 0;
                if (t == 'P')
                {
                    ma = tmp.front()->pr, s = tmp.front()->val;
                    for (int x = 1; x < tmp.size(); x++)
                        ma = max(ma, s + tmp[x]->pr), s += tmp[x]->val;
                }
                else
                {
                    ma = tmp.back()->su, s = tmp.back()->val;
                    for (int x = tmp.size()-2; x >= 0; x--)
                        ma = max(ma, s + tmp[x]->su), s += tmp[x]->val;
                }
                printf("%i\n", ma);
            break;    
        }
    }
}
