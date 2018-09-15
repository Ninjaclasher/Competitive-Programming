#include <bits/stdc++.h>

using namespace std;

struct point
{
    long long x, y;
    friend bool operator<(point &a, point &b)
    {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
    friend ostream &operator<<(ostream &os, point &a)
    {
        os<<a.x<<" "<<a.y;
        return os;
    }
};

static inline __attribute__((always_inline)) long long side(point &o, point &a, point &b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

static inline __attribute__((always_inline)) bool cw(point &o, point &a, point &b)
{
    return side(o, a, b) < 0;
}

static inline __attribute__((always_inline)) bool inTriangle(vector<point> po, point a)
{
    bool aa = cw(po[0], po[1], a), bb = cw(po[1], po[2], a), cc = cw(po[2], po[0], a);
    return aa == bb && bb == cc;
}

static inline __attribute__((always_inline)) int inc(int i, int mod)
{
    return (i+1)%mod;
}
static inline __attribute__((always_inline)) int dec(int i, int mod)
{
    return (i-1+mod)%mod;
}

vector<point> convex_hull(vector<point> arr)
{
    int k = 0;
    if (arr.size() <= 2)
        return arr;
    sort(arr.begin(), arr.end());
    vector<point> res(arr.size()<<1);
    for (int x = 0; x < arr.size(); x++)
    {
        while (k >= 2 && !cw(res[k-2], res[k-1], arr[x])) --k;
        res[k++] = arr[x];
    }
    int t = k+1;
    for (int x = arr.size()-2; x >= 0; x--)
    {
        while (k >= t && !cw(res[k-2], res[k-1], arr[x])) --k;
        res[k++] = arr[x];
    }
    res.resize(k-1);
    return res;
}

bool intersect(vector<point> a, vector<point> n)
{
    if (a[0].x == a[1].x)
        return n[0].x == n[1].x && n[0].x == a[0].x;
    long double m = (a[0].y-a[1].y)/(long double)(a[0].x-a[1].x);
    long double b = -m*a[0].x + a[0].y;
    return (m*n[0].x + b <= n[0].y) != (m*n[1].x + b <= n[1].y);
}

long double ang(point a, point b)
{
    return atan2(a.y-b.y, a.x-b.x);
}

#define FAST 1

unsigned long long get(point a, point b)
{
#if FAST 
    return (a.x * b.y) - (a.y * b.x);
#else
    return (a.y * b.x) - (a.x * b.y);
#endif
}

int main()
{
    int k, n;
    scanf("%i%i", &n, &k);
    vector<point> owned(k), other(n-k);
    for (auto &x : owned)
        scanf("%lli%lli", &x.x, &x.y);
    for (auto &x : other)
        scanf("%lli%lli", &x.x, &x.y);
    auto ret = convex_hull(owned);
#if FAST 
    reverse(ret.begin(), ret.end());
#endif
    unsigned long long area = 0;
    int sz = ret.size();
    point centroid = {0,0};
    for (int x = 0; x < sz; x++)
        centroid.x += ret[x].x, centroid.y += ret[x].y;
    centroid.x /= sz, centroid.y /= sz;
    vector<long double> angles(sz);
    for (int x = 0; x < sz; x++)
        angles[x] = ang(ret[x], centroid);
    int mii = 0;
    for (int x = 1; x < sz; x++)
        if (angles[x] < angles[mii])
            mii = x;
    rotate(angles.begin(), angles.begin()+mii, angles.end());
    rotate(ret.begin(), ret.begin()+mii, ret.end());
    vector<unsigned long long> psa(sz<<1);
    for (int x = 0; x < (sz<<1); x++)
    {
        auto cur = ret[x%sz], next = ret[inc(x, sz)];
        psa[x] = (area += get(cur, next));
    }
    area >>= 1;
    unsigned long long ma = area;
    for (auto &p : other)
    {
#if FAST 
        auto it = lower_bound(angles.begin(), angles.end(), ang(p, centroid));
        auto it2 = it;
        if (it == angles.begin())        
            it = angles.end();
        else if (it == angles.end())
            it2 = angles.begin();
        --it;
        int u1 = it-angles.begin(), u2 = it2-angles.begin();
        if (side(ret[u1], ret[u2], p) <= 0)
        {
            it = lower_bound(angles.begin(), angles.end(), ang(centroid, p));
            it2 = it;
            if (it == angles.begin())
                it = angles.end();
            else if (it == angles.end())
                it2 = angles.begin();
            --it;
            int l1 = it2-angles.begin(), l2 = it-angles.begin();
            while (l1 ^ u1)
            {
                int ch = (u1-l1+sz)%sz>>1;
                int m = (l1+ch)%sz;
                if (side(ret[m], ret[inc(m, sz)], p) < 0)
                    u1 = m;
                else
                    l1 = inc(m, sz);
            }
            swap(l2, u2);
            while (l2 ^ u2)
            {
                int ch = (u2-l2+sz)%sz>>1;
                int m = (l2+ch)%sz;
                if (-side(ret[m], ret[inc(m, sz)], p) < 0)
                    u2 = m;
                else
                    l2 = inc(m, sz);
            }
        }
        vector<int> po = {u1, u2};
        unsigned long long cur = area + get(ret[po[0]], p) + get(p, ret[po[1]]);
        if (po[1] > po[0])
            cur -= psa[dec(po[1], sz)]-(po[0]-1 >= 0 ? psa[po[0]-1] : 0);
        else
            cur -= area-(psa[dec(po[0], sz)]-(po[1]-1 >= 0 ? psa[po[1]-1] : 0));
#else
        vector<int> po;
        for (int x = 0; x < sz && po.size() < 3; x++)
        {
            auto next = ret[inc(x, sz)], prev = ret[dec(x, sz)];
            if (!intersect(vector<point>{p, ret[x]}, vector<point>{prev, next}))
                po.push_back(x);
        }
        if (po.size() != 2)
            continue;
        unsigned long long cur = area;
        if (inTriangle(vector<point>{p, ret[po[0]], ret[po[1]]}, ret[inc(po[0], sz)]))
        {
            cur -= psa[po[1]-1]-(po[0]-1 >= 0 ? psa[po[0]-1] : 0);
            cur += get(ret[po[0]], p) + get(p, ret[po[1]]);
        }
        else
        {
            cur -= psa[po[0]-1+sz]-psa[po[1]-1];
            cur += get(ret[po[1]], p) + get(p, ret[po[0]]);
        }
#endif
        ma = max(ma, cur);
    }
    printf("%llu.%c\n", ma>>1, (ma&1) ? '5' : '0');
}

