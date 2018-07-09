#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    char l[n+1];
    bool b = true;
    for (int x = 1; x <= n; x++)
    {
        cin >>l[x];
        if ((x == 1 || x == 2 || x == 3 || x == 5 || x == 8 || x == 13 || x == 21 || x == 34 || x == 55 || x == 89 || x == 144 || x == 233 || x == 377) && l[x] != 'A')
        {
            b = false;
            break;
        }
        else if (!(x == 1 || x == 2 || x == 3 || x == 5 || x == 8 || x == 13 || x == 21 || x == 34 || x == 55 || x == 89 || x == 144 || x == 233 || x == 377) && l[x] == 'A')
        {
            b = false;
            break;
        }
    }
    if (b)
        cout <<"That's quite the observation!";
    else
        cout <<"Bruno, GO TO SLEEP";
    return 0;
}
