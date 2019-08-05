#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    vector<char> arr(n);
    for (auto &x : arr)
    {
        string s;
        cin>>s;
        x = tolower(s[0]);
    }
    long long ans = 0;
    long long c = 0;
    char p = '\0';
    for (int x = 0; x < n; x++)
    {
        if (arr[x] != p)
        {
            ans += c * (c+1) / 2;
            c = 0;
            p = arr[x];
        }
        c++;
    }
    ans += c * (c+1) / 2;
    printf("%lli\n", ans % 1000000007);
}
