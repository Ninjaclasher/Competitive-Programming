#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1);

list<int> p;

int n;

long double query(long double x)
{
    printf("Q %.20Lf\n", x);
    fflush(stdout);
    long double a;
    scanf("%Lf", &a);
    return a;
}

long double xx, yy;

static inline long double f(long double x, int k)
{
    long double ret = 0;
    for (; k; k -= k&-k) 
        ret += sin((k&-k)*x);
    return ret;
}

static inline bool eq(long double a, long double b)
{
    return abs(a-b) < 1e-5;
}

void run(int cur, int cnt, int v)
{
    if (cnt > n || cnt+cur < n)
        return;
    if (!cur)
    {
        if (eq(f(xx, v), yy))
            p.push_back(v);
        return;
    }
    run(cur-1, cnt, v<<1);
    run(cur-1, cnt+1, v<<1|1);
}


void gen_pair()
{
    xx = rand()*PI/RAND_MAX;
    yy = query(xx);
}

void prune()
{
    gen_pair();
    for (auto it = p.begin(); it != p.end(); )
    {
        if (!eq(f(xx, *it), yy))
            it = p.erase(it);
        else
            ++it;
    }
}

int main()
{
    scanf("%i", &n);
    gen_pair();
    run(23, 0, 0);
    while (p.size() > 1)
        prune();
    assert(!p.empty());
    printf("A %i\n", *p.begin());
    fflush(stdout);
}
