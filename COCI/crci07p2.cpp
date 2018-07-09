#include <bits/stdc++.h>

using namespace std;

int minCost = INT_MAX, n;
vector<int> ff;
vector<vector<int>> ccs;

void next()
{
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> buf;
    buf.push(make_pair(0,make_pair(0,0)));
    while (!buf.empty())
    {
        int b = buf.top().first, a = buf.top().second.first, c = buf.top().second.second;
        buf.pop();
        if (c) b += ff[a];
        if (a == n-1)
        {
            minCost = min(minCost, b);
            break;
        }
        if (b < ccs[a][c])
        {
            ccs[a][c] = b;
            if (a+c+1 < n) buf.push(make_pair(b, make_pair(a+c+1, c+1)));
            if (a-c >= 0 && c) buf.push(make_pair(b, make_pair(a-c, c)));
        }
    }
}


int main()
{
    scanf("%i", &n);
    ff.resize(n);
    ccs.resize(n, vector<int>(n+1, INT_MAX));
    for (int x = 0; x < n; x++)
        scanf("%i", &ff[x]);
    next();
    printf("%i", minCost);
    return 0;
}
