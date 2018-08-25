#include <bits/stdc++.h>

using namespace std;

struct st
{
    int a, b, i;
    friend bool operator<(st q, st w)
    {
        return q.b > w.b || (q.b == w.b && q.a > w.a);
    }
};

int main()
{
    int n, a, b;
    char t;
    scanf("%i", &n);
    set<st> ss;
    vector<st> act;
    while(n--)
    {
        scanf(" %c%i", &t, &a);
        if (t == 'D')
        {
            scanf("%i", &b);
            act.push_back({-a, -b, act.size()+1});
            ss.insert({-a, -b, act.size()});
        }
        else
        {
            --a;
            auto cur = act[a];
            ss.erase(cur);
            auto it = ss.lower_bound(cur);
            for (; it != ss.end(); ++it)
                if (it->a <= cur.a)
                    break;
            if (it == ss.end())
                printf("NE\n");
            else
                printf("%i\n", it->i);
            ss.insert(cur);
        }
    }
}
