#include <bits/stdc++.h>

using namespace std;

const int MAXN = 805;

long long BIT[MAXN][MAXN];

void update(int i, int j, long long v)
{
    for (int x = i+1; x < MAXN; x += x&-x)
        for (int y = j+1; y < MAXN; y += y&-y)
            BIT[x][y] += v;
}

long long query(int i, int j)
{
    long long sum = 0;
    for (int x = i+1; x > 0; x -= x&-x)
        for (int y = j+1; y > 0; y -= y&-y)
            sum += BIT[x][y];
    return sum;
}

struct node
{
    long long v;
    int x, y;
    friend bool operator<(node a, node b)
    {
        return a.v < b.v || (a.v == b.v && (a.x < b.x || (a.x == b.x && a.y < b.y)));
    }
    friend bool operator>(node a, node b)
    {
        return a.v > b.v || (a.v == b.v && (a.x > b.x || (a.x == b.x && a.y > b.y)));
    }
};

int main()
{
    int n;
    scanf("%i", &n);
    vector<node> arr(n*n);
    priority_queue<node, vector<node>, greater<node>> buf;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            scanf("%lli", &arr[x*n+y].v);
            arr[x*n+y].x = x;
            arr[x*n+y].y = y;
            update(x, y, 1);
        }
    }
    sort(arr.begin(), arr.end());
    long long ans = 0;
    for (int x = 0; x < n*n; x++)
    {
        while (!buf.empty() && buf.top().v < arr[x].v)
        {
            update(buf.top().x, buf.top().y, -1);
            buf.pop();
        }
        long long cur = query(arr[x].x-1, arr[x].y-1);
        arr[x].v += cur;
        ans += cur;
        buf.push(arr[x]);
    }
    printf("%lli\n", ans);
}
