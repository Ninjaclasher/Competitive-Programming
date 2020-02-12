#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int l = 0, cur = 0, ma = 0;
    for (auto &x : s)
    {
        if (x == 'L')
            l++, cur++;
        else if (x != ' ')
            ma = max(ma, cur), cur = 0;
    }
    ma = max(ma, cur);
    printf("%i %i\n", l, ma);
}
