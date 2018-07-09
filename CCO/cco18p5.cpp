#include <bits/stdc++.h>

using namespace std;

vector<int> id(2000010), st(2000010), arr(1000005);
int n, k;

inline void build()
{
    for (int x = 0; x < n; x++)
        id[x+n] = x;
    for (int x = n-1; x > 0; x--)
        id[x] = arr[id[x<<1]] > arr[id[x<<1|1]] ? id[x<<1] : id[x<<1|1];
}

inline void update(int x, int v)
{
    st[x+=n] = v;
    for (x >>= 1; x; x >>= 1)
        st[x] = max(st[x<<1], st[x<<1|1]);
}

inline void update2(int x)
{
    x+=n;
    for (x >>= 1; x; x >>= 1)
        id[x] = arr[id[x<<1]] > arr[id[x<<1|1]] ? id[x<<1] : id[x<<1|1];
}

int query(int l, int r)
{
    if (l > r)
        return n;
    int ret = n;
    for (l += n, r += n+1; l < r; l>>=1, r>>=1)
    {
        if (l&1)
        {
            ret = arr[ret] > arr[id[l]] || (arr[ret] == arr[id[l]] && ret > id[l]) ? ret : id[l];
            l++;
        }
        if (r&1)
        {
            --r;
            ret = arr[ret] > arr[id[r]] || (arr[ret] == arr[id[r]] && ret > id[r]) ? ret : id[r]; 
        }
    }
    return ret;
}

inline bool replace(int l, int x, int r)
{
    return arr[x] >= arr[l] && arr[x] > arr[r];
}

inline void run(int x)
{
    int l = query(max(0, x-k+1), x-1), r = query(x+1, min(x+k-1, n-1));
    if (replace(l, x, r))
        update(x, arr[x] + max(arr[l], arr[r]));
}

int main()
{
    int q, a, b, c;
    scanf("%i%i%i", &n, &k, &q);
    for (int x = 0; x < n; x++)
        scanf("%i", &arr[x]);
    build();
    for (int x = 0; x < n; x++)
        run(x);
    printf("%i\n", st[1]);
    while (q--)
    {
        scanf("%i%i", &a, &b);
        --a;
        arr[a] = b;
        update2(a);
        int l = query(max(0, a-k+1), a-1), r = query(a+1, min(n-1, a+k-1));
        if (replace(l, a, r))
            update(a, arr[a] + max(arr[l], arr[r]));
        else
        {
            update(a, 0);
            if (l < n) run(l);
            if (r < n) run(r);
        }
        printf("%i\n", st[1]);
    }
}
