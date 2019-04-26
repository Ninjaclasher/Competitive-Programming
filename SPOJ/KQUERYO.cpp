#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30005;

int arr[MAXN];
vector<int> st[MAXN<<2];

vector<int> merge(vector<int> &a, vector<int> &b)
{
    vector<int> ret;
    int i = 0, j = 0;
    while (i < a.size() || j < b.size())
    {
        if (i == a.size())
            ret.push_back(b[j++]);
        else if (j == b.size())
            ret.push_back(a[i++]);
        else if (a[i] < b[j])
            ret.push_back(a[i++]);
        else
            ret.push_back(b[j++]);
    }
    return ret;
}

void build(int l, int r, int v)
{
    if (l == r)
    {
        st[v].push_back(arr[l]);
        return;
    }
    int m = l+r>>1;
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
    st[v] = merge(st[v<<1], st[v<<1|1]);
}

int query(int l, int r, int v, int li, int ri, int k)
{
    if (l > ri || r < li)
        return 0;
    if (l >= li && r <= ri)
        return st[v].end() - upper_bound(st[v].begin(), st[v].end(), k);
    int m = l+r>>1;
    return query(l, m, v<<1, li, ri, k) + query(m+1, r, v<<1|1, li, ri, k);
}

int main()
{
    int n, q;
    scanf("%i",&n);
    for (int x = 1; x <= n; x++)
        scanf("%i", &arr[x]);
    build(1, n, 1);
    scanf("%i", &q);
    int lst = 0;
    while (q--)
    {
        int a, b, c;
        scanf("%i%i%i", &a, &b, &c);
        a ^=lst;
        b ^= lst;
        c ^= lst;
        printf("%i\n", lst = query(1, n, 1, a, b, c));
    }
}
