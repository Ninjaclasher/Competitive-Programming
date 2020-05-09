#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y;
    scanf("%i%i%i", &n, &x, &y);
    int ans = 0;
    while (true)
    {
        ans++;
        int m = x+y>>1;
        if (m < n)
            x = m;
        else if(m > n)
            y = m;
        else
            break;
    }
    cout<<ans<<endl;
}
