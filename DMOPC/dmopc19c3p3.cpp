#include <bits/stdc++.h>

using namespace std;

const int MAXN = 150005;

vector<int> bit(MAXN * 2);

void increment(int x)
{
    x += MAXN;
    for (; x < bit.size(); x += x&-x)
        bit[x]++;
}

int query(int x)
{
    x += MAXN;
    int ret = 0;
    for (; x > 0; x -= x&-x)
        ret += bit[x];
    return ret;
}

int main()
{
    int n, a;
    long long ans = 0, cur = 0;
    scanf("%i", &n);
    // full prefix always possibility
    increment(0);
    while (n--)
    {
        scanf("%i", &a);
        cur += (a == 2 ? -1 : 1);
        // how many prefix sums can I take?
        ans += query(cur - 1); 
        increment(cur);
    }
    printf("%lli\n", ans);
}
