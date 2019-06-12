#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<vector<int>> adj(MAXN);
vector<long long> arr(MAXN), sum(MAXN), cnt(MAXN);
long long tot = 0;

void dfs(int u, int p)
{
    sum[u] = arr[u];
    for (auto &x : adj[u])
    {
        if (x != p)
        {
            dfs(x, u);
            cnt[u] += cnt[x] + (arr[u] * sum[x]);
            sum[u] += sum[x];
        }
    }
}

long long ma = 0;

void dfs2(int u, int p, long long upCnt=0, long long upSum=0)
{
    vector<long long> cur;
    long long curSum = 0, curCnt = 0;
    long long curAns = upCnt;
    long long threshold = tot - arr[u];
    for (auto &x : adj[u])
    {
        if (x != p)
        {
            curSum += sum[x];
            curCnt += cnt[x];
            curAns += cnt[x];
            cur.push_back(sum[x]);
        }
    }
    cur.push_back(threshold - curSum);
    sort(cur.begin(), cur.end());

    curAns += arr[u] * threshold;

    if (cur.back() >= threshold - cur.back())
        curAns += cur.back() * (threshold - cur.back());
    else
    {
        vector<long long> sub1, sub2;
        int n1 = cur.size() / 2;
        int n2 = cur.size() - n1;
        for (int x = 0; x < (1 << n1); x++)
        {
            long long cc = 0;
            for (int y = 0; y < n1; y++)
                if (x >> y & 1)
                    cc += cur[y];
            sub1.push_back(cc);
        }
        for (int x = 0; x < (1 << n2); x++)
        {
            long long cc = 0;
            for (int y = 0; y < n2; y++)
                if (x >> y & 1)
                    cc += cur[y + n1];
            sub2.push_back(cc);
        }
        sort(sub1.begin(), sub1.end());
        sort(sub2.rbegin(), sub2.rend());
        long long curMa = 0;
        for (int x = 0, y = 0; x < sub1.size(); x++)
        {
            while (y < sub2.size() && sub1[x] + sub2[y] > threshold / 2)
                y++;
            for (int z = -1; z <= 1; z++)
                if (y + z >= 0 && y + z < sub2.size())
                    curMa = max(curMa, (sub1[x] + sub2[y + z]) * (threshold - sub1[x] - sub2[y + z]));
        }
        curAns += curMa;
    }
    ma = max(ma, curAns);

    curSum += upSum;
    curCnt += upCnt;

    for (auto &x : adj[u])
        if (x != p)
            dfs2(x, u, curCnt - cnt[x] + (curSum - sum[x]) * arr[u], curSum + arr[u] - sum[x]);
}

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &arr[x]), tot += arr[x];
    for (int x = 2; x <= n; x++)
    {
        int p;
        scanf("%i", &p);
        adj[p].push_back(x);
        adj[x].push_back(p);
    }
    dfs(1, 1);
    dfs2(1, 1);
    for (int x = 1; x <= n; x++)
        ma += arr[x] * (arr[x] - 1);
    printf("%lli\n", ma);
}
