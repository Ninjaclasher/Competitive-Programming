#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

int bit[MAXN], arr[MAXN];

void update(int i, int v)
{
    for (; i < MAXN; i += i&-i)
        bit[i] += v;
}

int query(int i)
{
    int sum = 0;
    for (; i; i -= i&-i)
        sum += bit[i];
    return sum;
}

int n, a;

void run(int i)
{
    int act = arr[i] + query(arr[i]);
    printf("%i\n", abs(act-i));
    if (act < i)
    {
        update(arr[i], -1);
    }
    else if (act > i)
    {
        update(1, 1);
        update(arr[i], -1);
    }
}

int main()
{
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        arr[a] = x+1;
    }
    for (int x = 1; x <= n/2; x++)
    {
        run(x);
        run(n-x+1);
    }
    if (n&1)
        run(n/2 + 1);
}
