#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> h(n + 1);
    for (auto &x : h)
        scanf("%i", &x);
    vector<int> w(n);
    for (auto &x : w)
        scanf("%i", &x);
    int full = 0;
    int half = 0;
    for (int x = 0; x < n; x++)
    {
        full += w[x] * min(h[x], h[x + 1]);
        half += w[x] * abs(h[x] - h[x + 1]);
    }
    full += half / 2;
    half %= 2;
    if (!half)
        printf("%i\n", full);
    else
        printf("%i.5\n", full);
}
