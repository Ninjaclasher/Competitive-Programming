#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000000;
int r, c, mv[2];

vector<int> decrypt(int a)
{
    vector<int> ret(r*c);
    for (auto &x : ret)
    {
        x = a % 3;
        a /= 3;
    }
    return ret;
}

int encrypt(vector<int> &a) 
{
    int ans = 0;
    for (int x = a.size()-1; x >= 0; x--)
        ans = ans * 3 + a[x];
    return ans;
}

double dp[MAXN][2];

double solve(int state, int turn=1)
{
    double &t = dp[state][turn];
    if (!(t < 0))
        return t;
    int cur[14][14];
    vector<int> arr = decrypt(state);
    for (int x = 0; x < r; x++)
        for (int y = 0; y < c; y++)
            cur[x][y] = arr[x * c + y];
    vector<double> chances;
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            if (cur[x][y] == turn + 1)
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        if ((dx && dy) || (!dx && !dy)) continue;
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && nx < r && ny >= 0 && ny < c && cur[nx][ny])
                        {
                            int tt = cur[nx][ny];
                            cur[nx][ny] = cur[x][y];
                            cur[x][y] = 0;
                            vector<int> nxt(r*c);
                            for (int i = 0; i < r; i++)
                                for (int j = 0; j < c; j++)
                                    nxt[i * c + j] = cur[i][j];
                            chances.push_back(1 - solve(encrypt(nxt), turn ^ 1));
                            cur[x][y] = cur[nx][ny];
                            cur[nx][ny] = tt;
                        }
                    }
                }
            }
        }
    }
    sort(chances.rbegin(), chances.rend());
    int cnt = min((int)chances.size(), mv[turn]);
    t = 0;
    for (int x = 0; x < cnt; x++)
        t += chances[x];
    if (cnt > 0)
        t /= cnt;
    return t;
}


int main()
{
    for (int x = 0; x < MAXN; x++)
        for (int y = 0; y < 2; y++)
            dp[x][y] = -1;
    scanf("%i%i", &r, &c);
    vector<int> arr(r*c);
    for (auto &x : arr)
    {
        char cc;
        scanf(" %c", &cc);
        if (cc == 'J')
            x = 2;
        else if (cc == 'D')
            x = 1;
    }
    scanf("%i%i", &mv[1], &mv[0]);
    printf("%.3lf\n", solve(encrypt(arr)));
}
