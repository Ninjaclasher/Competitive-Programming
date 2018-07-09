#include <bits/stdc++.h>

using namespace std;

struct node
{
    int ch[2] = {0, 0};
    int val = 0;
};

node arr[1000000];
int cc = 1;

int build(int l, int r)
{
    int cur = cc++;
    if (l ^ r)
    {
        int m = l+r>>1;
        arr[cur].ch[0] = build(l, m);
        arr[cur].ch[1] = build(m+1, r);
        arr[cur].val = arr[arr[cur].ch[0]].val + arr[arr[cur].ch[1]].val;
    }
    return cur;
}

int update(int l, int r, int i, int v, int t)
{
    int cur = cc++;
    arr[cur] = arr[t];
    if (!arr[cur].ch[0])
    {
        arr[cur].val = v;
        return cur;
    }
    int m = l+r>>1;
    if (i <= m)
        arr[cur].ch[0] = update(l, m, i, v, arr[t].ch[0]);
    else
        arr[cur].ch[1] = update(m+1, r, i, v, arr[t].ch[1]);
    arr[cur].val = arr[arr[cur].ch[0]].val + arr[arr[cur].ch[1]].val;
    return cur;
}

int main()
{
    int n, m, k, a, b, c, d;
    char t;
    scanf("%i%i%i", &n, &m, &k);
    deque<pair<int,int>> qq;
    vector<pair<int,int>> root;
    root.push_back({build(1, n), 0});
    --k;
    for (int i = 0; i < m; i++)
    {
        scanf(" %c", &t);
        if (t != 'X')
            scanf("%i", &a);
        switch(t)
        {
            case 'F':
                root.push_back({update(1, n, a, !root.back().second, root.back().first), root.back().second});
            break;
            case 'D':
                root.push_back({update(1, n, a, root.back().second, root.back().first), root.back().second});
            break;
            case 'R':
                root.push_back(root[a]);
            break;
            case 'X':
                root.push_back({root.back().first, !root.back().second});
            break;
        }
        int ans = arr[root.back().first].val;
        if (root.back().second)
            ans = n-ans;
        while (!qq.empty() && qq.back().first < ans)
            qq.pop_back();
        qq.push_back({ans,i});
        printf("%i %i\n", ans, qq.front().first);
        if (qq.front().second == i-k)
            qq.pop_front();
    }
    fflush(stdout);
}
