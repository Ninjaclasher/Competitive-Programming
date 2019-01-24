#include <bits/stdc++.h>

using namespace std;

int chk(string a)
{
    map<string,int> mp;
    mp["jack"] = 11;
    mp["queen"] = 12;
    mp["king"] = 13;
    mp["ace"] = 14;
    return mp[a];
}

int main()
{
    deque<int> buf(52);
    string a;
    for (auto &x : buf)
    {
        cin >> a;
        x = chk(a);
    }
    int s[2] = {0, 0};
    int c = 0;
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop_front();
        if (u >= 11)
        {
            int cc = u-10;
            if (buf.size() >= cc)
            {
                for (int y = 0; y < cc; y++)
                    if (buf[y] >= 11)
                        goto NO;
                if (!c)
                    printf("Player A scores %i point(s).\n", cc);
                else
                    printf("Player B scores %i point(s).\n", cc);
                s[c] += cc;
            }
NO:;
        }
        c ^= 1;
    }
    printf("Player A: %i point(s).\n", s[0]);
    printf("Player B: %i point(s).\n", s[1]);
}
