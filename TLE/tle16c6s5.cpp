#include <bits/stdc++.h>

using namespace std;

class hull_optimizer 
{
    struct line 
    {
        long long m, b, value;
        double xlo;
        bool is_query;

        line(long long m, long long b, long long v, bool is_query)
            : m(m), b(b), value(v), xlo(-numeric_limits<double>::max()), is_query(is_query) {}

        double intersect(const line &l) const 
        {
            if (m == l.m)
                return numeric_limits<double>::max();
            return (double)(l.b - b)/(m - l.m);
        }

        bool operator<(const line &l) const 
        {
            if (l.is_query)
                return l.value < xlo;
            return m < l.m;
        }
    };

    set<line> hull;
    vector<line> conhull;

    inline bool has_prev(set<line>::iterator it) const { return it != hull.begin(); }

    inline bool has_next(set<line>::iterator it) const { return (it != hull.end()) && (++it != hull.end()); }

    inline bool irrelevant(set<line>::iterator it) const 
    {
        if (!has_prev(it) || !has_next(it))
            return false;
        set<line>::iterator prev = it, next = it;
        --prev;
        ++next;
        return (next->intersect(*prev) <= next->intersect(*it));
    }

public:

    void update()
    {
        for (set<line>::iterator x = hull.begin(); x != hull.end(); x++)
        {
            auto it = x;
            it++;
            conhull.push_back(*x);
            if (it != hull.end())
                conhull.back().xlo = x->intersect(*it);
        }
        hull.clear();
    }

    void add_line(long long m, long long b) 
    {
        line l(m, b, 0, false);
        set<line>::iterator it = hull.lower_bound(l);
        if (it != hull.end() && it->m == l.m) 
        {
            if (b < it->b) hull.erase(it++);
            else return;
        }
        it = hull.insert(it, l);
        if (irrelevant(it)) 
        {
            hull.erase(it);
            return;
        }
        while (has_prev(it) && irrelevant(--it)) hull.erase(it++);
        while (has_next(it) && irrelevant(++it)) hull.erase(it--);
    }

    long long query(long long x)
    {
        line l (0,0,x,true);
        auto it = lower_bound(conhull.begin(), conhull.end(), l);
        return it->m*x + it->b;
      
    }
};

vector<vector<long long>> dist(3001, vector<long long> (3001, LONG_MAX>>1));
vector<vector<pair<int,int>>> adj(3001);

int main() 
{
    int n, m, d, a, b, c;
    long long t = 0;
    scanf("%i%i%i", &n, &m, &d);
    vector<hull_optimizer> minCost (n+1);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
    }

    dist[1][0] = 0;
    queue<pair<int,int>> buf;
    buf.push(make_pair(1, 0));
    while (!buf.empty())
    {
        int u = buf.front().first, v = buf.front().second;
        buf.pop();
        for (auto &x : adj[u])
        {
            if (dist[u][v] + x.second < dist[x.first][v+1])
            {
                dist[x.first][v+1] = dist[u][v] + x.second;
                buf.push(make_pair(x.first, v+1));
            }
        }
    }

    for (int x = 1; x <= n; x++)
    {
        minCost[x].add_line(0, 4611686018427387903);
        for (int y = 0; y <= n; y++)
            if (dist[x][y] != 4611686018427387903)
                minCost[x].add_line(y, dist[x][y]);
        minCost[x].update();
    }
    while (d--)
    {
        scanf("%i%i", &a, &b);
        t += a;
        long long cc = minCost[b].query(t);
        if (cc >= 2305843009213693951)
            printf("Cannot Deliver\n");
        else
            printf("%lli\n", cc);
    }
    return 0;
}
