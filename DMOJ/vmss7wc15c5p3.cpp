#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main()
{
    vector<vector<int>> bit(5000, vector<int>(5000));
    int n;
    long long cc = 0;
    scanf("%i", &n);
    while (n--)
    {
        int a, b, c, t;
        scanf("%i%i%i%i", &t, &a, &b, &c);
        int d = a+b-2;
        if (t == 1)
            for (; a < 5000; a += a&-a)
                bit[d][a] += c;
        else
        {
            long long tt = 0;
            for (int x = a; x > 0; x -= x&-x)
                tt += bit[d][x];
            for (int x = a-c-1; x > 0; x-= x&-x)
                tt -= bit[d][x];
            cc = (cc+tt)%MOD;
        }
    }
    printf("%lli\n", cc);
}
