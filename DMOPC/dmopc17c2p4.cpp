#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin>>a;
    string bb = a, aa = a;
    reverse(aa.begin(), aa.end());
    for (int x = a.length()-2, xx = 0; x >= 0; x--, xx++)
    {
        bb.pop_back();
        aa.erase(0,1);
        if (aa == bb)
        {
            for (int y = 1; y < a.length() - bb.length()+1; y++)
            {
                if (bb == a.substr(y, x+1))
                {
                    printf("%i", x+1);
                    return 0;
                }
            }
        }
    }
}
