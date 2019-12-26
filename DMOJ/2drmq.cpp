#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

constexpr static inline int highest_bit(const int k)
{
    return 31 - __builtin_clz(k);
}

const int MAXN = 1001;
const int MAXM = 1001;
static const int LOGN = highest_bit(MAXN) + 1;
static const int LOGM = highest_bit(MAXM) + 1;
int spt[LOGN][MAXN][LOGM][MAXM];

void init(vector<vector<int>> arr)
{
        int N = arr.size();
        int M = arr[0].size();
        int LN = highest_bit(N) + 1;
        int LM = highest_bit(M) + 1;
        for (int ix = 0; ix < N; ix++)
        {
            for (int iy = 0; iy < M; iy++)
                spt[0][ix][0][iy] = arr[ix][iy];
            for (int jy = 1; jy < LM; jy++)
            {
                int k = 1 << (jy - 1);
                for (int iy = 0; iy < M - k; iy++)
                    spt[0][ix][jy][iy] = min(spt[0][ix][jy-1][iy], spt[0][ix][jy-1][iy+k]);
                for (int iy = M - k; iy < M; iy++)
                    spt[0][ix][jy][iy] = spt[0][ix][jy-1][iy];
            }
        }
        for (int jx = 1; jx < LN; jx++)
        {
            int k = (1 << (jx - 1));
            for (int ix = 0; ix < N - k; ix++)
                for (int jy = 0; jy < LM; jy++)
                    for (int iy = 0; iy < M; iy++)
                        spt[jx][ix][jy][iy] = min(spt[jx-1][ix][jy][iy], spt[jx-1][ix+k][jy][iy]);
            for (int ix = N - k; ix < N; ix++)
                for (int jy = 0; jy < LM; jy++)
                    for (int iy = 0; iy < M; iy++)
                        spt[jx][ix][jy][iy] = spt[jx-1][ix][jy][iy];
        }
}

int query(int lx, int rx, int ly, int ry)
{
    int kx = highest_bit(rx - lx + 1);
    int ky = highest_bit(ry - ly + 1);
    rx -= (1 << kx) - 1;
    ry -= (1 << ky) - 1;
    return min(min(spt[kx][lx][ky][ly], spt[kx][lx][ky][ry]), min(spt[kx][rx][ky][ly], spt[kx][rx][ky][ry]));
}
