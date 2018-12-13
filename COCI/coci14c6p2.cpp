#include <bits/stdc++.h>

using namespace std;

struct team
{
    int o, v, n;
    int tot()
    {
        return max(0, o) + max(0, v) + max(0, n);
    }
    friend bool operator <(team &a, team &b)
    {
        return a.tot() < b.tot();
    }
};

int main()
{
    int n;
    scanf("%i", &n);
    vector<team> aa(n);
    for (auto &x : aa)
        scanf("%i-%i-%i", &x.o, &x.v, &x.n);
    int m;
    scanf("%i", &m);
    vector<team> bb(m);
    string c;
    for (auto &x : bb)
    {
        cin>>c;
        for (auto &y : c)
        {
            if (y == 'O')
                x.o++;
            else if (y == 'N')
                x.n++;
            else
                x.v++;
        }
    }
    for (auto &t : aa)
    {
        vector<team> other;
        for (auto x : bb)
        {
            if (x.tot() == 1)
            {
                t.o -= x.o;
                t.v -= x.v;
                t.n -= x.n;
            }
            else
                other.push_back(x);
        }
        sort(other.begin(), other.end());
        int x;
        for (x = 0; x < other.size() && other[x].tot() != 3; x++);
        int cnt = other.size()-x;
        for (int msk = 0; msk < (1<<x); msk++)
        {
            auto cur = t;
            for (int y = 0; y < x; y++)
            {
                if (msk>>y&1)
                {
                    if (other[y].o)
                        cur.o--;
                    else if (other[y].v)
                        cur.v--;
                    else if (other[y].n)
                        cur.n--;
                }
                else
                {
                    if (other[y].o)
                    {
                        if (other[y].v)
                            cur.v--;
                        else if (other[y].n)
                            cur.n--;
                    }
                    else if (other[y].v)
                    {
                        if (other[y].n)
                            cur.n--;
                    }
                }
            }
            if (cur.tot() <= cnt)
            {
                printf("DA\n");
                goto nxt;
            }
        }
        printf("NE\n");
nxt:;
    }
}
