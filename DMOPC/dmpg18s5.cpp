#include <bits/stdc++.h>

using namespace std;

const int sq = 500;

int freq[500][200001];
vector<int> aa(200001);

inline void divis(int n, int p, int cc)
{
    for (int x = 1; x <= sqrt(n); x++)
    {
        if (!(n%x))
        {
            freq[p][x] += cc;
            if (n/x != x)
                freq[p][n/x] += cc;
        }
    }   
}

int main()
{
    int n, q, a, b, c, d;
    scanf("%i%i", &n, &q);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &aa[x]);
        divis(aa[x], x/sq, 1);
    }
    while (q--)
    {
        scanf("%i%i%i", &a, &b, &c);
        if (a == 1)
        {
            scanf("%i", &d);
            int cc = 0, x = 0;
            --b, --c;
            for (x = b; x%sq && x <= c; x++)
                cc += !(aa[x]%d);
            for (; x+sq <= c; x += sq)
                cc += freq[x/sq][d];
            for (; x <= c; x++)
                cc += !(aa[x]%d);
            printf("%i\n", cc);
        }
        else
        {
            --b;
            divis(aa[b], b/sq, -1);
            aa[b] = c;
            divis(aa[b], b/sq, 1);
        }
    }
}
