#include <bits/stdc++.h>

using namespace std;

vector<int> run(string &s)
{
    vector<int> arr(s.length());
    int prev = -1;
    for (int x = 0; x < s.length(); x++)
    {
        if (s[x] == '1')
            prev = x;
        if (!~prev)
            arr[x] = INT_MAX;
        else
            arr[x] = x - prev;
    }
    return arr;
}

int main()
{
    int n;
    scanf("%i", &n);
    string s;
    cin>>s;
    vector<int> a = run(s);
    reverse(s.begin(), s.end());
    vector<int> b = run(s);
    long long ans = 0;
    for (int x = 0; x < n; x++)
        ans += min(a[x], b[n-x-1]);
    printf("%lli\n", ans);
}
