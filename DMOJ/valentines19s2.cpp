#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, t, a, b;
    scanf("%i%i", &n, &q);
    assert(1 <= n && n <= 100000);
    assert(1 <= q && q <= 100000);
    vector<int> xx(n+1), yy(n+1);
    set<long long> pos;
    while (q--)
    {
        scanf("%i%i%i", &t, &a, &b);
        assert(1 <= t && t <= 2);
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        long long act = (long long)(a-1) * n + (b-1); 
        if (t == 1)
        {
            xx[a] ^= 1;
            yy[b] ^= 1;
            auto it = pos.find(act);
            if (it == pos.end())
                pos.insert(act);
            else
                pos.erase(it);
        }
        else
        {
            int ex = pos.find(act) != pos.end();
            printf("%i\n", xx[a] ^ yy[b] ^ ex);
        }
    }
}
