#include <bits/stdc++.h>

using namespace std;

struct node
{
    int lazy;
    int v[10];
};

vector<node> st(1000000);
vector<int> arr(300000);

void push(int l, int r, int v)
{
    st[v].lazy %= 10;
    if (st[v].lazy)
    {
        int ne[10];
        for (int x = 0; x < 10; x++)
            ne[(x+st[v].lazy)%10] = st[v].v[x];
        memcpy(st[v].v, ne, 40);
        if (l ^ r)
        {
            st[v<<1].lazy += st[v].lazy;
            st[v<<1|1].lazy += st[v].lazy;
        }
        st[v].lazy = 0;
    }
}

int query(int l, int r, int v, int li, int ri)
{
    push(l, r, v);
    if (l >= li && r <= ri)
    {
        int sum = 0;
        for (int x = 0; x < 10; x++)
            sum += st[v].v[x]*x;
        st[v].lazy++;
        push(l, r, v);
        return sum;
    }
    else if (l > ri || r < li)
        return 0;
    int m = l+r>>1;
    int s = query(l, m, v<<1, li, ri) + query(m+1, r, v<<1|1, li, ri);
    for (int x = 0; x < 10; x++)
        st[v].v[x] = st[v<<1].v[x] + st[v<<1|1].v[x];
    return s;
}

void build(int l, int r, int v)
{
    if (l == r)
    {
        st[v].v[arr[l]]++;
        return;
    }
    int m = l+r>>1;
    build(l, m, v<<1), build(m+1, r, v<<1|1);
    for (int x = 0; x < 10; x++)
        st[v].v[x] = st[v<<1].v[x] + st[v<<1|1].v[x];
}

int main()
{
    int n, m, a, b;
    char c;
    scanf("%i%i", &n, &m);
    for (int x = 1; x <= n; x++)
    {
        scanf(" %c", &c);
        arr[x] = c-'0';
    }
    build(1, n, 1);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        printf("%i\n", query(1, n, 1, a, b));
    }
}
