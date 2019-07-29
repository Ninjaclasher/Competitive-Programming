#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    vector<pair<int,int>> buf;
    for (int x = 0; x < n; x++)
    {
        while (!buf.empty() && buf.back().first <= arr[x])
            buf.pop_back();
        printf("%i ", buf.empty() ? x : x - buf.back().second);
        buf.push_back({arr[x], x});
    }
}
