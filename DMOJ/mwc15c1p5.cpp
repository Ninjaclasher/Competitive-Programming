#include <bits/stdc++.h>

using namespace std;

int compat(string a)
{
    int val = 0;
    for (int x = 0; x < a.size(); x++)
        val += pow((a[x]-'@')%10, x % 4 + 1);
    val %= 10;
    if (!val) val = 10;
    return val;
}

int main()
{
    string a, b;
    cin>>a>>b;
    for (auto &x : a)
        x = toupper(x);
    for (auto &x : b)
        x = toupper(x);
    printf("%i", compat(a)+compat(b));
    return 0;
}
