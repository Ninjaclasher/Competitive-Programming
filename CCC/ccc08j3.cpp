#include <bits/stdc++.h>

using namespace std;

int main()
{
    string in;
    getline(cin, in);
    int x = 1, y = 1, cc = 0;
    for (auto &c: in)
    {
        if (c >= 'A' && c <= 'Z')
        {
            int nx = (c-'A')/6+1, ny = (c-'A')%6+1;
            cc += abs(x-nx);
            cc += abs(y-ny);
            x = nx, y = ny;
        }
        else
        {
            int nx = 5, ny = 3;
            if (c == '-')
                ny++;
            else if (c == '.')
                ny += 2;
            cc += abs(x-nx);
            cc += abs(y-ny);
            x = nx, y = ny;
        }
    }
    cc += abs(x-6) + abs(y-5);
    printf("%i\n", cc);
}

