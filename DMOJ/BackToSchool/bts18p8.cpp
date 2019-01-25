#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int KLEN = 5000;

struct node
{
    int lazy;
    bitset<KLEN+1> msk;
} st[3*MAXN];

long long arr[MAXN];
long long k;

static inline __attribute__((always_inline)) void push(int l, int r, int v)
{
    if (st[v].lazy < 0)
        st[v].msk >>= -st[v].lazy;
    else if (st[v].lazy > 0)
        st[v].msk <<= st[v].lazy;
    else
        return;
    if (l ^ r)
        st[v<<1].lazy += st[v].lazy, st[v<<1|1].lazy += st[v].lazy;
    st[v].lazy = 0;
}

void build(int l, int r, int v)
{
    if (l == r)
    {
        st[v].msk.set(arr[l]-k);
        return;
    }
    int m = l+r>>1;
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
    st[v].msk = st[v<<1].msk | st[v<<1|1].msk;
}

void update(int l, int r, int v, int li, int ri, int val)
{
    push(l, r, v);
    if (l > ri || r < li)
        return;
    else if (l >= li && r <= ri)
    {
        st[v].lazy = val;
        push(l, r, v);
        return;
    }
    int m = l+r>>1;
    update(l, m, v<<1, li, ri, val);
    update(m+1, r, v<<1|1, li, ri, val);
    st[v].msk = st[v<<1].msk | st[v<<1|1].msk;
}

bitset<KLEN+1> query(int l, int r, int v, int li, int ri)
{
    push(l, r, v);
    if (l > ri || r < li)
        return bitset<KLEN+1>();
    else if (l >= li && r <= ri)
        return st[v].msk;
    int m = l+r>>1;
    return query(l, m, v<<1, li, ri) | query(m+1, r, v<<1|1, li, ri);
}

int main()
{
    int n, q, t, a, b, c;
    scanf("%i%i%lli", &n, &q, &k);
    assert (1 <= n && n <= 100000);
    assert (1 <= q && q <= 50000);
    assert (2 <= k && k <= 100000000000000LL);
    vector<bool> pr(10000005, true);
    vector<long long> prime;
    bitset<KLEN+1> sieve;
    sieve.flip();
    for (int x = 2; x < pr.size(); x++)
    {
        if (pr[x])
        {
            prime.push_back(x);
            for (int y = x*x; y < pr.size(); y += x)
                pr[y] = false; 
        }
    }
    for (auto &x : prime)
    {
        long long u = k+KLEN;
        if (k+x-((k%x) ? k%x : x) != (k+x-1)/x*x)
            abort();
        if (u-u%x != u/x*x)
            abort();
        for (long long y = (k+x-1)/x*x; y <= (k+KLEN)/x*x; y += x)
            if (y > x)
                sieve[y-k] = 0;
    }
    //
    vector<long long> pp;
    for (int x = KLEN; x >= 0; x--)
        if (sieve[x])
            pp.push_back(x);
    //
    for (int x = 1; x <= n; x++)
        scanf("%lli", &arr[x]), assert(k <= arr[x] && arr[x] <= k+KLEN);
    build(1, n, 1);
    while (q--)
    {
        scanf("%i%i%i", &t, &a, &b);
        if (t == 1)
        {
            auto ret = query(1, n, 1, a, b);
            bool found = false;
            for (int x = 0; !found && x < pp.size(); x++)
                if (ret[pp[x]])
                    printf("%lli\n", pp[x]+k), found =1;
            if (!found)
                printf("-1\n");
 /*           ret &= sieve;
            if (ret.none())
                printf("-1\n");
            else
            {
                for (int x = KLEN; x >= 0; x--)
                {
                    if (ret[x])
                    {
                        printf("%lli\n", k+x);
                        break;
                    }
                }
            }
*/
        }
        else if (t == 2)
        {
            scanf("%i", &c);
            update(1, n, 1, a, b, c);
        }
    }
}
