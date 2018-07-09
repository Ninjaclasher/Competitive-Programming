#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    while (n--)
    {
        string a;
        cin>>a;
        vector<string> aa;
        for (int x = 0; x < a.length(); x++)
            aa.push_back(a.substr(x, a.length()-x));
        sort(aa.begin(), aa.end());
        int c = aa[0].length()+1;
        for (int x = 1; x < a.length(); x++)
        {
            int l = min(aa[x].length(), aa[x-1].length());
            for (int y = 0; y < l; y++)
                if (aa[x][y] != aa[x-1][y])
                    l = y;
            c += aa[x].length() - l;
        }
        printf("%i\n", c);
    }
}
