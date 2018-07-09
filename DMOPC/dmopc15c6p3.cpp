#include <bits/stdc++.h>

using namespace std;

int main() 
{
    long long n, m, k, s = 0;
    int a, b, w = INT_MAX;
    scanf("%lli%lli%lli", &m, &n, &k);
    if (!k) return 0 * printf("0");
    vector<int> pp (m+2, n), dd(m+2);
    while (n--)
    {
        scanf("%i%i", &a, &b);
        dd[a]--;
        dd[b+1]++;
    }
    for (int x = 1, aa = 0; x < m+2; x++)
        aa += dd[x], pp[x] += aa;
    a = 1, b = 1;
    for (; s < k && b <= m; b++)
        s += pp[b];
    if (s < k)
        return 0 * printf("-1");
    --b;
    while (b <= m)
    {
        while (s >= k)
        {
            s -= pp[a];
            a++;
        }
        --a;
        s += pp[a];
        w = min(w, b-a+1);
        b++;
        s += pp[b];
    }
    printf("%i", w == INT_MAX ? -1 : w);
    return 0;
}
