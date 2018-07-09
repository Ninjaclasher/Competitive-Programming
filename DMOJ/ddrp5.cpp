#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> st(2, vector<int>(2100000));
vector<vector<int>> nd(2, vector<int>(2100000));
vector<int> arr(2000000);
int n;

static inline __attribute__((always_inline)) void build()
{
    for (int x = 1; x <= n; x++)
       st[0][x+n-1] = st[1][x+n-1] = arr[x], nd[0][x+n-1] = nd[1][x+n-1] = x;
    for (int i = n-1; i > 0; i--)
    {
        st[0][i] = min(st[0][i<<1], st[0][i<<1|1]);
        st[1][i] = max(st[1][i<<1], st[1][i<<1|1]);
        nd[0][i] = (st[0][i<<1] < st[0][i<<1|1] ? nd[0][i<<1] : nd[0][i<<1|1]);
        nd[1][i] = (st[1][i<<1] > st[1][i<<1|1] ? nd[1][i<<1] : nd[1][i<<1|1]);
    }
}

static inline __attribute__((always_inline)) void update(int i, int val)
{
    i += n-1;
    st[0][i] = st[1][i] = val;
    for (i>>= 1; i; i>>=1)
    {
        st[0][i] = min(st[0][i<<1], st[0][i<<1|1]);
        st[1][i] = max(st[1][i<<1], st[1][i<<1|1]);
        nd[0][i] = (st[0][i<<1] < st[0][i<<1|1] ? nd[0][i<<1] : nd[0][i<<1|1]);
        nd[1][i] = (st[1][i<<1] > st[1][i<<1|1] ? nd[1][i<<1] : nd[1][i<<1|1]);
    }
}

static inline __attribute__((always_inline)) pair<int,int> query(int l, int r, int t)
{
    pair<int,int> ret = {t ? INT_MIN : INT_MAX, 0};
    for (l += n-1, r += n; l < r; l>>=1, r>>=1)
    {
        if (l&1) 
        {
            if (t)
                ret = max(ret, {st[t][l], nd[t][l]});
            else
                ret = min(ret, {st[t][l], nd[t][l]});
            l++;
        }
        if (r&1) 
        {
            --r;
            if (t)
                ret = max(ret, {st[t][r], nd[t][r]});
            else
                ret = min(ret, {st[t][r], nd[t][r]});
        }
    }
    return ret;
}

static inline __attribute__((always_inline)) int query2(int l, int r, int t)
{
    int ret = t ? INT_MIN : INT_MAX;
    for (l += n-1, r += n; l < r; l>>=1, r>>=1)
    {
        if (l&1)
        {
            if (t)
                ret = max(ret, st[t][l]);
            else
                ret = min(ret, st[t][l]);
            l++;
        }
        if (r&1) 
        {
            --r;
            if (t)
                ret = max(ret, st[t][r]);
            else
                ret = min(ret, st[t][r]);
        }
    }
    return ret;
}

int main()
{
    fill(st[0].begin(), st[0].end(), INT_MAX);
    fill(st[1].begin(), st[1].end(), INT_MIN);
    int q, a, b, t, ans = 0;
    scanf("%i%i", &n, &q);
    int sqn = (int)round(sqrt(n));
    for (int x = 1; x <= n; x++)
        scanf("%i", &arr[x]);
    build();
    while (q--)
    {
        scanf("%i%i%i", &t, &a, &b);
        a ^= ans, b ^= ans;
        switch(t)
        {
            case 1:
                update(a, b);
            break;
            case 2:
            case 3:
                int l = (a-1)*sqn+1, r = b*sqn;
                t -= 2;
                pair<int,int> qa = query(l, r, t);
                int qb; 
                if (!t)
                    qb = min(query2(l, qa.second-1, t), query2(qa.second+1, r, t));
                else
                    qb = max(query2(l, qa.second-1, t), query2(qa.second+1, r, t));
                printf("%i\n", ans = qa.first+qb);
            break;
        }
    }
}
