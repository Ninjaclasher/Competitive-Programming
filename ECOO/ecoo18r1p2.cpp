#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int x = 0; x < 10; x++)
    {
        int n;
        scanf("%i", &n);
        vector<int> ret;
        int mi = INT_MAX;
        while (n--)
        {
            int i, r, mii = INT_MAX, a;
            scanf("%i%i", &i, &r);
            while (r--)
            {
                scanf("%i", &a);
                mii = min(mii, a);
            }
            if (mii < mi)
            {
                ret.clear();
                ret.push_back(i);
                mi = mii;
            }
            else if (mii == mi)
                ret.push_back(i);
        }
        printf("%i {", mi);
        sort(ret.begin(), ret.end());
        for (int y = 0; y < ret.size(); y++)
            printf("%i%c", ret[y], y == ret.size()-1 ? '}' : ',');
        printf("\n");
    }
}
