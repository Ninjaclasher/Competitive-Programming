#include <bits/stdc++.h>

using namespace std;

int calc(vector<char> &cur)
{
    int ret = 0;
    if (cur.size() == 0)
        ret += 3;
    else if (cur.size() == 1)
        ret += 2;
    else if (cur.size() == 2)
        ret += 1;
    for (auto &x : cur)
    {
        switch(x)
        {
            case 'A': ret++;
            case 'K': ret++;
            case 'Q': ret++;
            case 'J': ret++;
        }
    }
    return ret;
}

int main()
{
    string n;
    cin>>n;
    map<char,vector<char>> cards;
    char t = '0';
    for (auto &x : n)
    {
        if (x == 'C' || x == 'D' || x == 'H' || x == 'S')
            t = x;
        else
            cards[t].push_back(x);
    }
    int tot = 0, cur = 0;
    printf("Cards Dealt              Points\n");
    for (auto &x : vector<string>({"Clubs", "Diamonds", "Hearts", "Spades"}))
    {
        printf("%s", x.c_str());
        for (auto &y : cards[x[0]])
            printf(" %c", y);
        cur = calc(cards[x[0]]);
        printf(" %i\n", cur);
        tot += cur;
    }
    printf("Total %i\n", tot);
}
