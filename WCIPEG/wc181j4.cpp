#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, p = -2;
    scanf("%i%i", &n, &m);
    int cnt = 0;
    while (m--)
    {
        scanf("%i", &a);
        if (abs(a-p) == 1)
            cnt++;
        else
            cnt+=2;
        p = a;
    }
    cout<<cnt<<endl;
}
