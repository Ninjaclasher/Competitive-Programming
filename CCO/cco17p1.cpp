#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> ans;
    int k;
    scanf("%i", &k);
    int n = 5000;
    while (k)
    {
        while (n*(n-1)/2 > k)
            n--;
        ans.push_back(n);
        k -= n*(n-1)/2;
    }
    int c = 1;
    vector<pair<int,int>> ed;
    for (auto x : ans)
    {
        int b = c;
        for (int y = 0; y < x-1; y++, c++)
            ed.push_back({c, c+1});
        ed.push_back({c, b});
        ed.push_back({1, c});
        c++;
    }
    printf("%i %i\n", c-1, ed.size());
    for (auto &x : ed)
        printf("%i %i\n", x.first, x.second);
}
