#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, r = 0, o = 0, y = 0, g = 0, b = 0, bl = 0;
    string cc;
    scanf("%i", &n);
    while (n--)
    {
        cin>>cc;
        if (cc=="red") r++;
        else if (cc=="orange") o++; 
        else if (cc=="yellow") y++; 
        else if (cc=="green") g++; 
        else if (cc=="blue") b++;
        else if (cc=="black") bl++; 
    }
    vector<pair<int,char>> q {make_pair(r, 'r'), make_pair(o, 'o'), make_pair(y, 'y'), make_pair(g, 'g'), make_pair(b, 'b'), make_pair(bl, 'B')};
    sort(q.rbegin(),q.rend());
    vector<char> colour;
    while (q[0].first)
    {
        bool set = false;
        for (auto &x : q)
        {
            if (x.first && (colour.empty() || x.second != colour.back()))
            {
                colour.push_back(x.second);
                x.first--;
                sort(q.rbegin(), q.rend());
                set = true;
                break;
            }
        }
        if (!set) break;
    }
    printf("%i\n", colour.size());
    return 0;
}
