#include <bits/stdc++.h>

using namespace std;

vector<int> arr(30);
int n;
long long ans = 0;

long long factorial(int v)
{
    long long ret = 1;
    for (int x = 2; x <= v; x++)
        ret *= x;
    return ret;
}

void run(int k, int prev=0)
{
    if (k == 0)
    {
        long long cur = factorial(n);
        for (auto &x : arr)
            cur /= factorial(x);
        ans += cur;
        return;
    }
    for (int x = prev; x < 26; x++)
    {
        arr[x]++;
        run(k-1, x);
        arr[x]--;
    }
}

int main()
{
    int k;
    scanf("%i%i", &n, &k);
    string s;
    cin>>s;
    for (auto &x : s)
        if (x != '*')
            arr[x - 'a']++;
    run(k);
    printf("%lli\n", ans);
}
