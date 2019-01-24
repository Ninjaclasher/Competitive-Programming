#include <bits/stdc++.h>

using namespace std;

vector<string> a, b;

vector<int> ans;
int m, n;

bool dfs(int i, string aa, string bb)
{
    if (aa == bb && aa.size() > 0)
        return true;
    if (i == m-1)
        return false;
    for (int x = 0; x < n; x++)
    {
        if (dfs(i+1, aa+a[x], bb+b[x]))
        {
            ans.push_back(x);
            return true;
        }
    }
    return false;
}


int main()
{
    scanf("%i%i", &m, &n);
    a.resize(n), b.resize(n);
    for (auto &x : a)
        cin>>x;
    for (auto &x : b)
        cin>>x;
    if (dfs(0, "", ""))
    {
        printf("%i\n", ans.size());
        reverse(ans.begin(), ans.end());
        for (auto &x : ans)
            printf("%i\n", x+1);
    }
    else
        printf("No solution.\n");
}
