#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int cur, cnt = 0, add = 0;
    cin>>cur;
    string o;
    for (cin>>o; o != "EOF"; cin>>o)
    {
        if (o == "TAKE")
        {
            cnt++, add++;
            cur++;
            if (cur == 1000)
                cur = 1;
        }
        else if (o == "SERVE")
            add--;
        else if (o == "CLOSE")
        {
            printf("%i %i %i\n", cnt, add, cur);
            add = 0, cnt = 0;
        }
    }
}
