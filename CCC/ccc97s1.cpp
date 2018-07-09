#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, a;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i", &a);
        vector<pair<int,int>> aa;
        for (int x = 1; x <= sqrt(a); x++)
        {
            if (!(a%x))
            {
                int y = a/x;
                for (auto &z : aa)
                {
                    if ((z.first+z.second) == abs(y-x) || abs(z.first-z.second) == (y+x))
                    {
                        printf("%i is nasty\n", a);
                        goto fin;
                    }
                }
                aa.push_back(make_pair(x,y));
            }
        }
        printf("%i is not nasty\n", a);
        fin:;
    }
    return 0;
}
