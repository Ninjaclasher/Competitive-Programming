#include <bits/stdc++.h>

using namespace std;

int fuckyouxiaowuc1()
{
    printf("\n");
    return 0;
}

int main() 
{
    string a;
    do getline(cin, a); while (a.empty());
    for (int x = 0; x < a.length(); x++)
    {
        string b = a.substr(x, a.length());
        while (!b.empty())
        {
            string c = b;
            reverse(c.begin(), c.end());
            if (c == b && !(b.length()&1))
                return 0 * printf("Even") * fuckyouxiaowuc1();
            b.pop_back();
        }
    }
    printf("Odd") * fuckyouxiaowuc1();
    return 0;
}
