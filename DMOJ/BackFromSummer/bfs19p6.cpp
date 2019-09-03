#include <bits/stdc++.h>

using namespace std;

const int A = 13, B = 8;
const int AA = ((1 << A) - 1), BB = ((1 << B) - 1);

const int MAXN = 100005;

const vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73};

int store[1 << B][1 << A], tstore[1 << A][1 << B];
vector<int> ans(MAXN, INT_MAX);

int factor(int n)
{
    int ret = 0;
    for (int x = 0; x < primes.size(); x++)
        if (n % primes[x] == 0)
            ret |= 1 << x;
    return ret;
}

int main()
{
    int n, a;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        a = factor(a);
        int top = a >> B;
        int bot = a & BB;
        int inv = top ^ AA;
        store[bot][AA]++;
        for (int v = inv; v; v = (v - 1) & inv)
            store[bot][AA & ~v]++;
    }
    for (int x = 0; x <= AA; x++)
        for (int y = 0; y <= BB; y++)
            tstore[x][y] = store[y][x];
    for (int x = 0; x < (1 << (A + B)); x++)
    {
        int top = x >> B;
        int bot = x & BB;
        int val = tstore[top][0];
        for (int y = bot; y; y = (y - 1) & bot)
            val += tstore[top][y];
        ans[val] = min(ans[val], __builtin_popcount(x));
    }
    for (int x = n-1; x >= 1; x--)
        ans[x] = min(ans[x], ans[x+1]);
    for (int x = 1; x <= n; x++)
        printf("%i%c", ans[x], x == n ? '\n' : ' ');
}
