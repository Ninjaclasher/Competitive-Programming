#include <bits/stdc++.h>

using namespace std;

void full(int n, string &s)
{
    int acount = 0, bcount = 0, ccount = 0;
    for (auto &x : s)
    {
        if (x == 'A') acount++;
        else if (x == 'B') bcount++;
        else if (x == 'C') ccount++;
        else abort();
    }
    s += s;
    s = '\0' + s;
    vector<int> apsa(s.size());
    vector<int> bpsa(s.size());
    vector<int> cpsa(s.size());
    for (int x = 1; x < s.size(); x++)
    {
        apsa[x] = apsa[x-1] + (s[x] == 'A');
        bpsa[x] = bpsa[x-1] + (s[x] == 'B');
        cpsa[x] = cpsa[x-1] + (s[x] == 'C');
    }
    int ans = INT_MAX;
    for (int x = 1; x <= n; x++)
    {
        // assume [A][B][C]
        {
        int cur = acount - (apsa[x+acount-1] - apsa[x-1]);
        int bina = bpsa[x+acount-1] - bpsa[x-1];
        cur += cpsa[x+acount+bcount-1] - cpsa[x+acount-1];
        cur += max(0, -bina + (apsa[x+acount+bcount-1] - apsa[x+acount-1]));
        ans = min(ans, cur);
        }
        // assume [A][C][B]
        {
        int cur = acount - (apsa[x+acount-1] - apsa[x-1]);
        int cina = cpsa[x+acount-1] - cpsa[x-1];
        cur += bpsa[x+acount+ccount-1] - bpsa[x+acount-1];
        cur += max(0, -cina + (apsa[x+acount+ccount-1] - apsa[x+acount-1]));
        ans = min(ans, cur);
        }
    }
    printf("%i\n", ans);
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    string s;
    cin>>s;
    n = s.length();
    full(n, s);
}
