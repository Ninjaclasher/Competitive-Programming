#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a;
    scanf("%i", &n);
    priority_queue<int, vector<int>, greater<int>> buf;
    long long ans = 0;
    while (n--)
    {
        scanf("%i", &a);
        buf.push(a);
    }
    while (buf.size() > 1)
    {
        int a = buf.top();
        buf.pop();
        int b = buf.top();
        buf.pop();
        ans += a+b;
        buf.push(a+b);
    }
    printf("%lli\n", ans);
}
