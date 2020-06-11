#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k, a, b;
    scanf("%i%i%i", &n, &m, &k);
    vector<vector<int>> arr(k+1);
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        arr[a].push_back(b);
    }
    long long ans = 0;
    vector<int> ret;
    for (int x = 1; x <= k; x++)
    {
        sort(arr[x].rbegin(), arr[x].rend());
        ans += arr[x][0];--m;
        for (int y = 1; y < arr[x].size(); y++)
            ret.push_back(arr[x][y]);
    }
    sort(ret.rbegin(), ret.rend());
    int i=0;
    while (m--)
    {
        ans += ret[i];
        i++;
    }
    cout<<ans<<endl;
}
