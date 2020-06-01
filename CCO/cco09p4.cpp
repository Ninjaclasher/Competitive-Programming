#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;

int ans[MAXN];

int query(int x, int y)
{
    printf("0 %i %i\n", x, y);
    int v;
    scanf("%i", &v);
    return v;
}

void report(int x, int y)
{
    printf("1 %i %i\n", x, y);
}

int n;

void solve(vector<int> &bot, vector<int> &cap)
{
    assert(bot.size() == cap.size());
    if (bot.empty())
        return;
    if (bot.size() == 1)
    {
        report(bot[0], cap[0]);
        return;
    }
    int cur_bot = bot[0];
    vector<int> l_cap, r_cap, l_bot, r_bot;
    int cur_cap = -1;
    for (auto &x : cap)
    {
        int v = query(cur_bot, x);
        if (v == 0)
            cur_cap = x;
        else if (v > 0)
            l_cap.push_back(x);
        else
            r_cap.push_back(x);
    }
    assert(cur_cap > 0);
    report(cur_bot, cur_cap);
    for (int x = 1; x < bot.size(); x++)
    {
        int v = query(bot[x], cur_cap);
        if (v < 0)
            l_bot.push_back(bot[x]);
        else
            r_bot.push_back(bot[x]);
    }
    solve(l_bot, l_cap);
    solve(r_bot, r_cap);
}

int main()
{
    srand(time(NULL));
    scanf("%i", &n);
    vector<int> cap(n), bot(n);
    iota(cap.begin(), cap.end(), 1);
    iota(bot.begin(), bot.end(), 1);
    random_shuffle(cap.begin(), cap.end());
    random_shuffle(bot.begin(), bot.end());
    solve(bot, cap);
}
