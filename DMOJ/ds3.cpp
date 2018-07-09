#include <bits/stdc++.h>

using namespace std;

int arr[1000001], mst[4000001], gst[4000001], fst[4000001];

int main()
{
    fill(mst, mst+4000001, INT_MAX);
    int n, m, a, b;
    char t;
    scanf("%i%i", &n, &m);
    int nLog = 1 << (int)(ceil(log2(n)));
    for (int x = 1; x <= n; x++)
        scanf("%i", &arr[x]), mst[nLog+x] = arr[x], gst[nLog+x] = arr[x], fst[nLog+x]++;
    for (int x = nLog; x > 0; x--)
    {
        mst[x] = min(mst[x<<1], mst[x<<1|1]), gst[x] = __gcd(gst[x<<1], gst[x<<1|1]);
        if (gst[x] == gst[x<<1])
            fst[x]+=fst[x<<1];
        if (gst[x] == gst[x<<1|1])
            fst[x]+=fst[x<<1|1];
    }
    while(m--)
    {
        scanf(" %c%i%i", &t, &a, &b);
        b++;
        switch(t)
        {
            case 'C':
            {
                arr[a] = --b;
                a += nLog;
                mst[a] = gst[a] = b;
                for (a>>=1; a > 0; a >>= 1)
                {
                    mst[a] = min(mst[a<<1], mst[a<<1|1]), gst[a] = __gcd(gst[a<<1], gst[a<<1|1]), fst[a] = 0;
                    if (gst[a] == gst[a<<1])
                        fst[a]+=fst[a<<1];
                    if (gst[a] == gst[a<<1|1])
                        fst[a]+=fst[a<<1|1];
                }
            }
            break;
            case 'M':
            {
                int ans = INT_MAX;
                for (a += nLog, b += nLog; a < b; a >>= 1, b >>= 1)
                {
                    if (a&1) ans = min(ans, mst[a++]);
                    if (b&1) ans = min(ans, mst[--b]);
                }
                printf("%i\n", ans);
            }
            break;
            case 'G':
            case 'Q':
            {
                int ans = 0, f = 0;
                a += nLog, b += nLog;
                for (int aa = a, bb = b; aa < bb; aa >>= 1, bb >>= 1)
                {
                    if (aa&1) ans = __gcd(ans, gst[aa++]);
                    if (bb&1) ans = __gcd(ans, gst[--bb]);
                }
                if (t == 'G')
                    printf("%i\n", ans);
                else
                {
                    for (; a < b; a >>= 1, b >>= 1)
                    {
                        if (a&1)
                        {
                            if (ans == gst[a]) f += fst[a];
                            a++;
                        }
                        if (b&1 && ans == gst[--b]) f += fst[b];
                    }
                    printf("%i\n", f);
                }
            }
            break;
        }
    }
}
