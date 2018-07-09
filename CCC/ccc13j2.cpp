#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string a;
    cin>>a;
    for (auto &x : a)
    {
        if (!(x == 'I' || x == 'O' || x == 'S' || x == 'H' || x == 'Z' || x == 'X' || x == 'N'))
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
