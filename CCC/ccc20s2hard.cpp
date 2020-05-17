#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int MN = 4001 * 4001;

bool vis[MN];
int buf[MN];
int cnt[MN], arr[MN], aa[MN], comp1[MN], comp2[MN];

bool can_escape(int M, int N, vector<vector<int>> v)
{
    int _c = 0;
    int _all = M * N;
    for (int x = 1; x <= M; x++)
        for (int y = 1; y <= N; y++, _c++)
            aa[x * y]++, comp1[_c] = v[x][y];
    for (int x = 1; x <= _all; x++)
        aa[x] = cnt[x] = cnt[x-1] + aa[x];
    int _d = 0;
    for (int x = 1; x <= M; x++)
        for (int y = 1; y <= N; y++)
            arr[aa[x * y]--] = _d++;

    int l = 0, r = 0;
    buf[r++] = 0;
    _c--;
    while (l < r)
    {
        int u = buf[l++];
        int vv = comp1[u];
        if (vis[vv]) continue;
        vis[vv] = 1;
        for (int x = cnt[vv-1] + 1; x <= cnt[vv]; x++)
            buf[r++] = arr[x];
    }
    return vis[_all];
}
