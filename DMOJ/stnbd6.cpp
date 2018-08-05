#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

struct complexx
{
    long double re, im;
    
    inline void neg()
    {
        long double t = re*re + im*im;
        re /= t, im /= -t;
    }

    friend complexx operator + (complexx a, complexx b){ return {a.re + b.re, a.im + b.im}; }
    friend complexx operator +=(complexx &a, complexx b) { return a = a+b; }
    friend complexx operator - (complexx a, complexx b){ return {a.re - b.re, a.im - b.im}; }
    friend complexx operator * (complexx a, complexx b){ return {a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re}; }
    friend complexx operator *=(complexx &a, complexx b){ return a = a * b;}
    friend complexx operator / (complexx a, long double b) { return {a.re / b, a.im / b}; }
    friend complexx operator /=(complexx &a, long double b) { return a = a / b; }
};

const long double PI = acos(-1);
const long double TPI = 2*PI;
const int LM = 18;
const int MM = 1<<LM;

vector<vector<int>> adj(MAXN);
int arr[MAXN], sz[MAXN];
long long psa[MM];
bool vis[MAXN];
complexx tot[MM], cur[MM], fft[MM], arr1[MM], arr2[MM];
int n;

static inline __attribute__((always_inline)) int rev (int x, int L)
{
    int ret = 0;
    for (int i = 0; i < L; i++)
    {
        ret = (ret << 1) | (x&1);
        x >>= 1;
    }
    return ret;
}

void FFT(complexx *arr, int M, int L, bool inv=false)
{
    for (int x = 0; x < M; x++)
    {
        int y = rev(x, L);
        if (x < y)
            swap(arr[x], arr[y]);
    }
    for (int m = 2, i = 0; m <= M; m <<= 1, i++)
    {
        int mm = m>>1;
        complexx w = {cos(TPI/m), sin(TPI/m)};
        if (inv)
            w.neg();
        for (int off = 0; off < M; off += m)
        {
            complexx x = {1, 0};
            for (int j = off; j < off+mm; j++)
            {
                auto a = arr[j], b = x*arr[j+mm];
                arr[j] = a+b;
                arr[j+mm] = a-b;
                x *= w;
            }
        }
    }
}

static inline __attribute__((always_inline)) void IFFT(complexx *arr, int M, int L)
{
    FFT(arr, M, L, true);
    for (int x = 0; x < M; x++)
        arr[x] /= M;
}

int dfs(int u, int p)
{
    sz[u] = 1;
    for (auto &x : adj[u])
        if ((x ^ p) && !vis[x])
            sz[u] += dfs(x, u);
    return sz[u];
}

int centroid(int u, int p, int nn)
{
    for (auto &x : adj[u])
        if ((x ^ p) && !vis[x] && (sz[x]<<1) > nn)
            return centroid(x, u, nn);
    return u;
}

int cursz, curst;

int dfs2(int u, int p, int l)
{
    sz[u] = 1;
    if (l >= cursz)
        cursz = l+1;
    tot[curst+l].re++;
    for (auto &x : adj[u])
        if ((x ^ p) && !vis[x])
            sz[u] += dfs2(x, u, l+arr[x]);
    return sz[u];
}

struct range
{
    int l, sz;
    friend bool operator < (range a, range b)
    {
        return a.sz < b.sz;
    }
} buf[MAXN+1];

static inline __attribute__((always_inline)) int nTwo(int n)
{
    return 32-__builtin_clz(n);
}

void solve(int c)
{
    c = centroid(c, c, sz[c]);
    vis[c] = 1;
    memset(tot, 0, (++++++sz[c])<<6);
    int cc = 0;
    buf[cc++] = {0, 1};
    tot[0].re++;
    cursz = 0, curst = 1;
    for (auto &x : adj[c])
    {
        if (!vis[x])
        {
            dfs2(x, x, arr[x]);
            buf[cc++] = {curst, cursz};
            curst += cursz;
            cursz = 0;
        }
    }
    sort(buf, buf+cc);
    for (int i = 0; i < cc-1; i++)
    {
        auto &a = buf[i], &b = buf[i+1];
        int szz = a.sz+b.sz;
        int L = nTwo(szz);
        int M = 1<<L;
        memset(arr1, 0, M<<5);
        memset(arr2, 0, M<<5);
        memcpy(arr1, tot+a.l, a.sz<<5);
        memcpy(arr2, tot+b.l, b.sz<<5);
        FFT(arr1, M, L);
        FFT(arr2, M, L);
        for (int x = 0; x < M; x++)
            arr1[x] *= arr2[x];
        IFFT(arr1, M, L);
        for (int x = 0; x < szz; x++)
            psa[x+arr[c]] += (long long)round(arr1[x].re);
        for (int x = 0; x < a.sz; x++)
            tot[b.l+x] += tot[a.l+x];
    }
    for (auto &x : adj[c])
        if (!vis[x])
            solve(x);
}

int main()
{
    int a, b, q;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
        scanf("%i", &arr[x]);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    solve(1);
    for (int x = 1; x < MM; x++)
        psa[x] += psa[x-1];
    scanf("%i", &q);
    while (q--)
    {
        scanf("%i%i", &a, &b);
        printf("%lli\n", psa[b]-psa[a-1]);
    }
}
