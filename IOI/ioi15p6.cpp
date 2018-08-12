#include <bits/stdc++.h>

using namespace std;

int revmp[10000], sz[10000], par[150], c, u, h;
int dist[150][150];

int balanced(int N, int hh)
{
    if (!~hh)
        return 0;
    int szs[2] = {0, 0};
    for (int x = 1; x <= c; x++)
    {
        if (x == hh)
            continue;
        szs[revmp[x] < revmp[hh]] += sz[x];
    }
    if (szs[0] > N/2 || szs[1] > N/2)
        return 0;
    else if (N-szs[0]-szs[1] <= N/2)
        return 2;
    return 1;
}

static inline __attribute__((always_inline)) int dis(int x, int y)
{
    if (~dist[x][y])
        return dist[x][y];
    return dist[x][y] = dist[y][x] = getDistance(x, y);
}

int find(int n)
{
    if (n ^ par[n]) return par[n] = find(par[n]);
    return n;
}

int majority(vector<int> &arr, int tb = -1)
{
    if (arr.empty())
        return tb;
    vector<int> ne;
    if (arr.size()&1)
        tb = arr.back();
    for (int x = 1; x < arr.size(); x += 2)
        if (dis(u,arr[x]) + dis(u,arr[x-1]) - dis(arr[x], arr[x-1]) > 2*revmp[h])
            ne.push_back(arr[x]), par[arr[x-1]] = arr[x];
    return majority(ne, tb);
}

int ddis(int x, int y, int N)
{
    for (int i = 0; i < N; i++)
        if (find(x) == find(i))
            for (int j = 0; j < N; j++)
                if (find(y) == find(j) && ~dist[i][j])
                    return dis(u, i) + dis(u, j) - dis(i, j);
    return dis(u, x) + dis(u, y) - dis(x, y);
}

int hubDistance(int N, int sub)
{
    vector<int> distTo(150);
    map<int,int> mp;
    memset(sz, 0, sizeof(sz));
    memset(revmp, 0, sizeof(revmp));
    memset(dist, -1, sizeof(dist));
    iota(par, par+150, 0);
    c = 0, u = 0;
    int ma = 0;
    for (int x = 1; x < N; x++)
        if (dis(0, x) > ma)
            ma = dis(0, x), u = x;
    for (int x = 1; x < N; x++)
        if (x ^ u)
        	ma = max(dis(u, x), ma);
    int r = INT_MAX, h1 = -1, h2 = -1;
    for (int x = 0; x < N; x++)
    {
        distTo[x] = (dis(u, x)+dis(0, u)-dis(0, x))/2;
        if (!mp[distTo[x]])
        {
            mp[distTo[x]] = ++c;
            revmp[c] = distTo[x];
        }
        sz[mp[distTo[x]]]++;
    }
    for (int x = 1; x <= c; x++)
    {
        int cur_r = max(ma-revmp[x], revmp[x]);
        if (cur_r < r)
             r = cur_r, h1 = x, h2 = -1;
        else if (cur_r == r)
             h2 = x;
    }
    int b1 = balanced(N, h1), b2 = balanced(N, h2);
    if (!b1 && !b2)
        return -r;
    else if (b1 == 2 || b2 == 2)
        return r;
    if (!b1) h1 = -1;
    if (!b2) h2 = -1;
    if (~h1 && ~h2)
        abort();
    h = (~h1) ? h1 : h2;
    vector<int> nd;
    for (int x = 0; x < N; x++)
        if (distTo[x] == revmp[h])
            nd.push_back(x);
    int maj = majority(nd);
    if (!~maj)
        return r;
    int cnt = 0;
    for (auto &x : nd)
    {
        if (ddis(x, maj, N) > 2*revmp[h])
        {
            cnt++;
            if (cnt > N/2)
                return -r;
        }
    }
    return r;
}
