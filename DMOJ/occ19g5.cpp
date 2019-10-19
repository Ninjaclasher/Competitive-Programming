#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

struct ed
{
    int a, b, w, i;
};

vector<ed> edg(5001);
struct intt
{
    int i;
    friend bool operator<(intt a, intt b)
    {
        return edg[a.i].w < edg[b.i].w;
    }
};

vector<bool> reduced(MAXN);

int mi = INT_MAX, n, bnd;

priority_queue<intt> buf;

void solve(int k)
{
    if (k > bnd)
        return;
    vector<int> removed;
    while (!buf.empty() && (reduced[edg[buf.top().i].a] || reduced[edg[buf.top().i].b]))
    {
        int v = buf.top().i;
        buf.pop();
        removed.push_back(v);
    }
    if (buf.empty())
    {
        mi = min(mi, 10 * k * k);
        for (auto &x : removed)
            buf.push({x});
        return;
    }
    int i = buf.top().i;
    buf.pop();
    removed.push_back(i);
    int aa = edg[i].a, bb = edg[i].b, ww = edg[i].w;
    mi = min(mi, 10 * k * k + ww);
    reduced[aa] = 1;
    solve(k+1);
    reduced[aa] = 0;
    reduced[bb] = 1;
    solve(k+1);
    reduced[bb] = 0;
    for (auto &x : removed)
        buf.push({x});
}



int main()
{
    int m, a, b, w;
    scanf("%i%i", &n, &m);
    bnd = min(m, 11);
    for (int x = 1; x <= m; x++)
    {
        scanf("%i%i%i", &a, &b, &w);
        edg[x] = {a, b, w, x};
        buf.push({x});
    }
    solve(0);
    cout<<mi<<endl;
}
