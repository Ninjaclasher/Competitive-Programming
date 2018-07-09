#include <bits/stdc++.h>

using namespace std;

int ma;
vector<int> card(4);
vector<bool> used(4);

void run(int ca, int maa)
{
    used[ca] = true;
    if (used[0] && used[1] && used[2] && used[3])
    {
        if (maa <= 24)
            ma = max(ma, maa);
        used[ca] = false;
        return;
    }
    vector<int> us;
    for (int x = 0; x < 4; x++)
    {
        if (!used[x])
        {
            us.push_back(x);
            run(x, maa+card[x]);
            run(x, abs(maa-card[x]));
            run(x, maa*card[x]);
            if (maa%card[x] == 0)
                run(x, maa/card[x]);
            if (maa && card[x]%maa == 0)
                run(x, card[x]/maa);
        }
    }
    if (us.size() == 2)
    {
        used[us[0]] = used[us[1]] = true;
        run(us[0], maa+(card[us[0]] * card[us[1]]));
        if (card[us[0]]%card[us[1]] == 0)
            run(us[0], abs(maa - (card[us[0]] / card[us[1]])));
        if (card[us[1]]%card[us[0]] == 0)
            run(us[0], abs(maa - (card[us[1]] / card[us[0]])));

        run(us[0], maa*(card[us[0]]+card[us[1]]));
        if (maa%(card[us[0]]+card[us[1]]) == 0)
            run(us[0], maa/(card[us[0]]+card[us[1]]));
        if (maa && (card[us[0]]+card[us[1]])%maa == 0)
            run(us[0], (card[us[0]]+card[us[1]])/maa);
        used[us[0]] = used[us[1]] = false;
    }
    used[ca] = false;
}

int main()
{
    int n;
    scanf("%i", &n);
    while (n--)
    {
        ma = 0;
        fill(used.begin(), used.end(), false);
        for (int x = 0; x < 4; x++)
            scanf("%i", &card[x]);
        run(0, card[0]);
        run(1, card[1]);
        run(2, card[2]);
        run(3, card[3]);
        printf("%i\n", ma);
    }   
}
