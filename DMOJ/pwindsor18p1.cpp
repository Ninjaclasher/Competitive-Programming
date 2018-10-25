#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a;
    cin>>a;
    for (int x = 0; x < a.length()-3; x++)
        if (a.substr(x, 4) == "java")
            return 0 * printf("%i\n", x);
    printf("%u\n", a.length());
}
