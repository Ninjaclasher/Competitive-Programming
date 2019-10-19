#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

vector<long long> a(10);
vector<vector<int>> arr(MAXN, vector<int>(10));
vector<bool> vis(MAXN);

int k;

bool cmp(vector<int> &aa, vector<int> &bb)
{
    for (int x = 0; x < k; x++)
        if (aa[x] < bb[x])
            return true;
        else if (aa[x] > bb[x])
            return false;
    return true;
}

int main()
{
    int n;
    scanf("%i%i", &n, &k);
    for (int x = 0; x < k; x++)
        scanf("%lli", &a[x]);
    for (int x = 0; x < n; x++)
        for (int y = 0; y < k; y++)
            scanf("%i", &arr[x][y]);
    int cnt = 0;
    bool bad = true;
    while (bad)
    {
        bad = false;
        for (int x = 0; x < n; x++)
        {
            if (vis[x])
                continue;
            for (int y = 0; y < k; y++)
                if (arr[x][y] > a[y])
                    goto SKIP;
            vis[x] = 1;
            cnt++;
            bad = true;
            for (int y = 0; y < k; y++)
                a[y] += arr[x][y];
SKIP:;
        }
    }
    cout<<cnt<<endl;
}
