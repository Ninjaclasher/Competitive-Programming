#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cnt = 0;
    char c;
    for (int x = 0; x< 5; x++)
    {
        scanf(" %c", &c);
        if (c == 'P')
            cnt++;
    }
    cout<<cnt<<endl;
}
