#include <bits/stdc++.h>

using namespace std;

class SegmentTree
{
public:
    SegmentTree(const int);
    void updateRange(int, int, int, int, int, int, bool);

    inline void getAct(const int x, const int p)
    {
        lazy[x] = {max(min(lazy[x].first, lazy[p].first), lazy[p].second), min(max(lazy[x].second, lazy[p].second), lazy[p].first)};
    }
    vector<pair<int,int>> lazy;
    int nLog;
};

SegmentTree::SegmentTree(const int n)
{
    nLog = 1<<(int)(ceil(log2(n)));
    lazy.resize(nLog*4);
}

void SegmentTree::updateRange(int v, int s, int e, int l, int r, int val, bool t)
{
    if (s > r || e < l) return;
    if (s >= l && e <= r)
    {
        if (t) 
            lazy[v] = {min(lazy[v].first, val), min(lazy[v].second, val)};
        else 
            lazy[v] = {max(lazy[v].first, val), max(lazy[v].second, val)};
        return;
    }
    getAct(v<<1, v);
    getAct(v<<1|1, v);
    lazy[v] = {INT_MAX, 0};
    int mid = s + ((e-s) >> 1);
    updateRange(v<<1, s, mid, l, r, val, t);
    updateRange(v<<1|1, mid + 1, e, l, r, val, t);
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[])
{
    SegmentTree st(n);
    for (int x = 0; x < k; x++)
        st.updateRange(1, 0, st.nLog-1, left[x], right[x], height[x], op[x]-1);

    for (int x = 1; x < st.nLog; x++)
        st.getAct(x<<1, x), st.getAct(x<<1|1, x);
    for (int x = st.nLog, y = 0; y < n; x++, y++)
        finalHeight[y] = min(st.lazy[x].first, st.lazy[x].second);
}
