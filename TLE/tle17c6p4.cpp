#include <bits/stdc++.h>

using namespace std;

struct event
{
    int x, xx, y, t;
    friend bool operator<(event &a, event &b)
    {
        return a.y < b.y;
    }
};

vector<vector<int>> cur(2, vector<int>(500005));

int query(int i, int c)
{
    int s = 0;
    for (; i > 0; i -= i&-i)
        s += cur[c][i];
    return s;
}

void update(int i, int v, int c)
{
    for(; i < cur[c].size(); i += i&-i)
        cur[c][i] += v;
}

int main() 
{
    vector<event> ev;
    vector<int> dn(500005);
    int n, a, b, c, d, prev = 0;
    long long s = 0;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i%i%i%i", &a, &b, &c, &d);
        ev.push_back({a, c, b, 1});
        ev.push_back({a, c, d, -1});
    }
    sort(ev.begin(), ev.end());
    for (int x = 0; x < ev.size(); x++)
    {
        update(ev[x].x, ev[x].t, 1), update(ev[x].xx, -ev[x].t, 1);
        if (ev[x].y ^ ev[x+1].y)
        {
            for (int y = prev; y <= x; y++)
            {
                if (!dn[ev[y].x])
                {
                    if ((!query(ev[y].x, 0)) + (!query(ev[y].x, 1)) + (!query(ev[y].x-1, 0)) + (!query(ev[y].x-1, 1)) == 3)
                        s++;
                    dn[ev[y].x] = true;
                }
                if (!dn[ev[y].xx])
                {    
                    if ((!query(ev[y].xx, 0)) + (!query(ev[y].xx, 1)) + (!query(ev[y].xx-1, 0)) + (!query(ev[y].xx-1, 1)) == 3)
                        s++;
                    dn[ev[y].xx] = true;
                }
            }
            for (; prev <= x; prev++)
                update(ev[prev].x, ev[prev].t, 0), update(ev[prev].xx, -ev[prev].t, 0), dn[ev[prev].x] = dn[ev[prev].xx] = false;
        }
    }
    printf("%lli", s);
}
