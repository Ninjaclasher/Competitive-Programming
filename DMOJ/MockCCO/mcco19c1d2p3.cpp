#include <bits/stdc++.h>

using namespace std;

template <typename T = long double>
struct line
{
    T m, b;
    int i;
    long double x;
    bool query = false;
    const bool operator<(const line ot) const
    {
        if (ot.query || query)
            return x < ot.x;
        return m < ot.m || (m == ot.m && b < ot.b);
    }
    long double intersect(const line ot) const
    {
        if (m == ot.m)
            return LONG_MAX;
        return (b - ot.b)/(long double)(ot.m - m);
    }
};

template <typename T = long double>
struct CHT
{
    vector<line<T>> hull;
    vector<line<T>> lines;
    bool initialized;
    CHT() : initialized (false) {}
    
    CHT(vector<line<T>> &l) : initialized (false)
    {
        lines = l;
        init();
    }
    
    void add_line(T m, T b, int i)
    {
        assert (!initialized);
        lines.push_back({m, b, i});
    }
    
    void init()
    {
        assert (!initialized);
        sort(lines.begin(), lines.end());
        for (auto &x : lines)
        {
            while (!hull.empty() && hull.back().m == x.m)
                hull.pop_back();
            while (hull.size() >= 2 && x.intersect(hull[hull.size()-2]) <= hull.back().intersect(hull[hull.size()-2]))
                hull.pop_back();
            hull.push_back(x);
        }
        hull[0].x = LONG_MIN;
        for (unsigned int x = 1; x < hull.size(); x++)
            hull[x].x = hull[x].intersect(hull[x-1]);
        initialized = true;
    }

    T query(T x)
    {
        assert (initialized);
        auto it = lower_bound(hull.begin(), hull.end(), line<T>{0, 0, (long double)x, true});
        --it;
        return it->m * x + it->b;
    }
};

int main()
{
    CHT<long long> cht;
    int n;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        int a, b;
        scanf("%i%i", &a, &b);
        cht.add_line(a, b, x);
    }
    cht.init();
    vector<int> ids;
    for (auto &x : cht.hull)
        ids.push_back(x.i);
    sort(ids.begin(), ids.end());
    for (int x = 0; x < ids.size(); x++)
        printf("%i%c", ids[x], x == ids.size() - 1 ? '\n' : ' ');
}
