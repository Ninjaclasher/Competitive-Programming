#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> o(n);
    for (auto &x : o)
        scanf("%i", &x);
    int cur = 0;
    for (int x = o.size()-1; x >= 0; x--)
    {
        if (cur && o[x] && (o[x] != cur))
            return 0 * printf("-1\n");
        if (o[x])
            cur = o[x];
        else
            o[x] = cur;
        if (cur)
            cur--;
    }
    if (o[0] > 1)
        return 0 * printf("-1");
    o[0] = 1;

    int len = 0;
    int mi = 0, ma = 0;
    for (int x = 0; x < n; x++)
    {
        if (!o[x])
        {
            len++;
        }
        else
        {
            if (len)
                ma += len+1, mi++;
            else
            {

            if (x && o[x-1] != o[x]-1)
                ma++, mi++;
            }
            len = 0;
        }
    }
    if (len)
        ma += len;
    cout<<mi<<" "<<ma<<endl;
}
