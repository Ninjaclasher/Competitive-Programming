#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> aa(51, vector<long long>(2001)), vis(51, vector<long long>(2001));
vector<vector<pair<int,pair<int,int>>>> st(2, vector<pair<int,pair<int,int>>>(5000));
int n = 0, k;

bool dfs(int a, int b, int c, int d)
{
    if (aa[a][b] >= k) return false;
    int t = 0;
    vector<int> id(2);
    n++;
    st[0][++id[0]] = make_pair(t++, make_pair(a, b));
    while (id[0] || id[1])
    {
        if (!id[0])
            tie(a, b) = st[1][id[1]--].second;
        else if (!id[1])
            tie(a, b) = st[0][id[0]--].second;
        else if (st[0][id[0]].first > st[1][id[1]].first)
            tie(a, b) = st[0][id[0]--].second;
        else
            tie(a, b) = st[1][id[1]--].second;
        if (a == c && b == d)
            return true;
        if (a + 1 <= c && vis[a+1][b] < n)
        {
            if (aa[a+1][b] < k)
                st[0][++id[0]] = make_pair(t++, make_pair(a+1, b)), vis[a+1][b] = n;
        } 
        else
            id[0] = 0;
        if (b + 1 <= d && vis[a][b+1] < n)
        {
            if (aa[a][b+1] < k)
                st[1][++id[1]] = make_pair(t++, make_pair(a, b+1)), vis[a][b+1] = n;
        } 
        else
            id[1] = 0;
    }
    return false;
}

int main()
{
    int l, w, q, t, a, b, c, d;
    long long f;
    scanf("%i%i%i%i", &l, &w, &k, &q);
    while(q--)
    {
        scanf("%i%i%i%i%i", &t, &a, &b, &c, &d);
        switch(t)
        {
            case 1:
                scanf("%lli", &f);
                for (int x = a; x <= c; x++)
                    for (int y = b; y <= d; y++)
                        aa[x][y] += f;
            break;
            case 2:
                printf("%s\n", dfs(a, b, c, d) ? "yes" : "no");
            break;
        }
    }
}
