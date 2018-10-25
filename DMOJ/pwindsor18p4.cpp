#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    vector<int> f(266), g(256);
    cin>>a>>b;
    for (auto &x : a)
        f[x]++;
    for (auto &x : b)
        g[x]++;
    for (int x = 32; x < 266; x++)
        if (f[x] ^ g[x])
            return 0 * printf("%c\n", x);
}
