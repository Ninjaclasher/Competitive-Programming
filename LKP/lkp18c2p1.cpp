#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a;
    scanf("%i%i", &n, &m);
    priority_queue<int,vector<int>,greater<int>> buf;
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        buf.push(a);
    }
    for (int x = 0; x < m; x++)
    {
        int u = buf.top();
        buf.pop();
        printf("%i\n", u);
        u++;
        buf.push(u);
    }
}
