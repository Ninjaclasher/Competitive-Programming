#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a = "9780921418";
    char q, w, e;
    scanf(" %c %c %c", &q, &w, &e);
    a += q;
    a += w;
    a += e;
    int cur = 1;
    long long ans = 0;
    for (auto &x : a)
    {
        ans += (x-'0')*cur;
        cur ^= 2;
    }
    printf("The 1-3-sum is %lli\n", ans);
}
