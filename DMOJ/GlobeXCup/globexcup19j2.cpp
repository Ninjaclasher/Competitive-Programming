#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
long long ma = LONG_MIN;
vector<vector<int>> arr(6, vector<int>(10));

void run(int i, long long cur, int lft)
{
    if (lft < 0)
        return;
    if (i == 6)
    {
        ma = max(ma, cur);
        return;
    }
    for (int x = 0; x < 10; x++)
        run(i+1, cur + arr[i][x], lft - x);
}

int main()
{
    scanf("%i%i%i%i", &n, &m, &a, &b);
    for (auto &x : arr)
        for (auto &y : x)
            scanf("%i", &y);
    run(0, 0, min(n/a, m/b));
    printf("%lli\n", ma);
}
