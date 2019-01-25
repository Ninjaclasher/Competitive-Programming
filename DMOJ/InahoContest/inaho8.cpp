#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int LOGN = 18;
const int MOD = 1000000007;

int spt[LOGN][MAXN], //sparse table
    sum[LOGN][MAXN], // sum
    prod[LOGN][MAXN], // product
    mi[LOGN][MAXN], // min
    ma[LOGN][MAXN], // max
    gc[LOGN][MAXN], // gcd
    band[LOGN][MAXN], // bitwise and
    bor[LOGN][MAXN], // bitwise or
    bxor[LOGN][MAXN], // bitwise xor
    cnt[2][LOGN][MAXN], // cnt > K, cnt < K
    mik[2][LOGN][MAXN]; // v_i > K, v_i < K
int h[MAXN], val[MAXN];

vector<int> adj[MAXN];
int n, q, k;

int DEFAULT[15] = {0, 0, 0, 0, 1, INT_MAX, INT_MIN, 0, (1<<30)-1, 0, 0, 0, 0, k, k};

int comb(int op, int a, int b)
{
    switch(op)
    {
        case 3:
        case 11:
        case 12:
            return a+b;
        case 4:
            return (long long)a*b%MOD;
        case 5:
            return min(a, b);
        case 6:
            return max(a, b);
        case 7:
            return __gcd(a, b);
        case 8:
            return a&b;
        case 9:
            return a|b;
        case 10:
            return a^b;
        case 13:
            if (a == k) return b;
            else if (b == k) return a;
            else return min(a, b);
        case 14:
            if (a == k) return b;
            else if (b == k) return a;
            else return max(a, b);
    }
    abort();
}

void dfs(int u, int p)
{
    h[u] = h[p]+1;
    spt[0][u] = p;
    sum[0][u] = mi[0][u] = ma[0][u] = gc[0][u] = band[0][u] = bor[0][u] = bxor[0][u] = prod[0][u] = val[u];
    bool lk = (val[u] < k);
    bool gk = (val[u] > k);
    cnt[lk][0][u] = 1;
    cnt[gk][0][u] = 0;
    mik[lk][0][u] = val[u];
    mik[!lk][0][u] = k;
    
    for (auto &x : adj[u])
        if (x ^ p)
            dfs(x, u);
}

void build()
{
    for (int x = 1; x < LOGN; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            int o = spt[x-1][y];
            spt[x][y] = spt[x-1][o];
            sum[x][y] =    comb(3,  sum[x-1][y],    sum[x-1][o]);
            prod[x][y] =   comb(4,  prod[x-1][y],   prod[x-1][o]);
            mi[x][y] =     comb(5,  mi[x-1][y],     mi[x-1][o]);
            ma[x][y] =     comb(6,  ma[x-1][y],     ma[x-1][o]);
            gc[x][y] =     comb(7,  gc[x-1][y],     gc[x-1][o]);
            band[x][y] =   comb(8,  band[x-1][y],   band[x-1][o]);
            bor[x][y] =    comb(9,  bor[x-1][y],    bor[x-1][o]);
            bxor[x][y] =   comb(10, bxor[x-1][y],   bxor[x-1][o]);
            cnt[0][x][y] = comb(11, cnt[0][x-1][y], cnt[0][x-1][o]);
            cnt[1][x][y] = comb(12, cnt[1][x-1][y], cnt[1][x-1][o]);
            mik[0][x][y] = comb(13, mik[0][x-1][y], mik[0][x-1][o]);
            mik[1][x][y] = comb(14, mik[1][x-1][y], mik[1][x-1][o]);
        }
    }
}

int lca(int a, int b)
{
    if (h[a] > h[b])
        swap(a, b);
    int d = h[b]-h[a];
    for (int x = LOGN-1; x >= 0; x--)
        if (d>>x&1)
            b = spt[x][b];
    if (a == b)
        return a;
    for (int x = LOGN-1; x >= 0; x--)
        if (spt[x][a] != spt[x][b])
            a = spt[x][a], b = spt[x][b];
    return spt[0][a];
}

int run(int a, int d, int op, int arr[LOGN][MAXN])
{
    int ret = DEFAULT[op];
    for (int x = LOGN-1; x >= 0; x--)
    {
        if (d>>x&1)
        {
            ret = comb(op, ret, arr[x][a]);
            a = spt[x][a];
        }
    }
    return ret;
}

int query(int op, int a, int b)
{
    int c = lca(a, b);
    int da = h[a]-h[c]+1, db = h[b]-h[c];
    int ret1, ret2;
    switch(op)
    {
        case 3:
            ret1 = run(a, da, op, sum);
            ret2 = run(b, db, op, sum);
        break;
        case 4:
            ret1 = run(a, da, op, prod);
            ret2 = run(b, db, op, prod);
        break;
        case 5:
            ret1 = run(a, da, op, mi);
            ret2 = run(b, db, op, mi);
        break;
        case 6:
            ret1 = run(a, da, op, ma);
            ret2 = run(b, db, op, ma);
        break;
        case 7:
            ret1 = run(a, da, op, gc);
            ret2 = run(b, db, op, gc);
        break;
        case 8:
            ret1 = run(a, da, op, band);
            ret2 = run(b, db, op, band);
        break;
        case 9:
            ret1 = run(a, da, op, bor);
            ret2 = run(b, db, op, bor);
        break;
        case 10:
            ret1 = run(a, da, op, bxor);
            ret2 = run(b, db, op, bxor);
        break;
        case 11:
            ret1 = run(a, da, op, cnt[0]);
            ret2 = run(b, db, op, cnt[0]);
        break;
        case 12:
            ret1 = run(a, da, op, cnt[1]);
            ret2 = run(b, db, op, cnt[1]);
        break;
        case 13:
            ret1 = run(a, da, op, mik[0]);
            ret2 = run(b, db, op, mik[0]);
        break;
        case 14:
            ret1 = run(a, da, op, mik[1]);
            ret2 = run(b, db, op, mik[1]);
        break;
        default:
            abort();
    }
    return comb(op, ret1, ret2);
}

int main()
{
    scanf("%i%i%i", &n, &q, &k);
    assert(1 <= n && n <= 100000);
    assert(1 <= q && q <= 100000);
    assert(1 <= k && k <= 1000);
    DEFAULT[13] = DEFAULT[14] = k;
    for (int x = 1; x <= n; x++)
        scanf("%i", &val[x]), assert(1 <= val[x] && val[x] <= 1000);
    int a, b, r = 1, t;
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    build();
    while (q--)
    {
        scanf("%i%i", &t, &a);
        assert(1 <= t && t <= 14);
        assert(1 <= a && a <= n);
        if (t == 1)
            r = a;
        else
        {
            scanf("%i", &b);
            assert(1 <= b && b <= n);
            if (t == 2)
                printf("%i\n", r);
            else
                printf("%i\n", query(t, a, b));
        }
    }
}
