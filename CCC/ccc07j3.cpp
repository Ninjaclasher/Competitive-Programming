#include <bits/stdc++.h>

using namespace std;

set<int> ss({100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000});
vector<int> mp({0, 100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000});

int main()
{
    int n, a;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i", &a);
        ss.erase(ss.find(mp[a]));
    }
    long long s = 0;
    for (auto &x : ss)
        s += x;
    scanf("%i", &a);
    if (a*ss.size() > s)
        printf("deal\n");
    else
        printf("no deal\n");
}

