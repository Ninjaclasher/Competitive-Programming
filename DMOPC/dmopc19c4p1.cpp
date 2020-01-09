#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    while (n--)
    {
        string s;
        cin>>s;
        int cnt = 0;
        for (auto &x : s)
        {
            if (x == '(')
                cnt++;
            else if (x == ')')
                cnt--;
            else if (!('0' <= x && x <= '9'))
                cnt = -1;
            if (cnt < 0)
                break;
        }
        if (cnt)
            printf("NO\n"); 
        else
            printf("YES\n");
    }
}
