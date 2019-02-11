#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    int l = 0;
    int cur = 0;
    priority_queue<int,vector<int>,greater<int>> buf;
    int cnt = 0, mi = 0;
    while (cur < n)
    {
        while (l <= cur)
        {
            buf.push(arr[l]);
            l++;
        }
        while (!buf.empty() && buf.top() <= mi)
            buf.pop();
        if (buf.empty())
            return 0 * printf("-1\n");
        cur += buf.top();
        mi = buf.top();
        buf.pop();
        ++cnt;
    }
    printf("%i\n", cnt);
}
