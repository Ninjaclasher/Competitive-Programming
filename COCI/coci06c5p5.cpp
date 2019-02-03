#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int dp[MAXN][MAXN];
deque<int> arr;

int solve(int l, int r)
{
    int &cur = dp[l][r];
    if (~cur)
        return cur;
    if (l == r)
        return arr[l];
    return cur = max(arr[l] - solve(l+1, r), arr[r] - solve(l, r-1));
}

int main()
{
    int n;
    scanf("%i", &n);
    arr.resize(n);
    for (auto &x : arr)
    {
        scanf("%i", &x);
        x &= 1;
    }
    int cnt = 0;
    for (int x = 0; x < n; x++)
    {
        memset(dp, -1, sizeof dp);
        cnt += arr[0] - solve(1, n-1) > 0;
        arr.push_back(arr.front());
        arr.pop_front();
    }
    printf("%i\n", cnt);
}
