#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, m;
    long long ans = 0;
    scanf("%i%i", &n, &x);
    priority_queue<int> buf;
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &m);
        buf.push(m);
    }
    while (x--)
    {
        int u = buf.top();
        buf.pop();
        ans += u;
        if (!u)
            ++u;
        buf.push(--u);
    }
    printf("%lli\n", ans);
}

