#include <bits/stdc++.h>

using namespace std;

bool palin(string a)
{
    string b = a;
    reverse(b.begin(), b.end());
    return a == b;
}

int main()
{
    string a;
    cin>>a;
    for (int x = 1; x < a.size(); x++)
    {
        if (palin(a.substr(0, x)) && palin(a.substr(x)))
            return 0 * printf("YES\n");
    }
    printf("NO\n");
}

