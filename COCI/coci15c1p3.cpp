#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a;
    scanf("%i", &n);
    multiset<int> gg;
    int cnt = 0;
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        auto it = gg.find(a);
        if (it == gg.end())
            cnt++;
        else
            gg.erase(it);
        gg.insert(a-1);
    }
    printf("%i\n", cnt);
}
