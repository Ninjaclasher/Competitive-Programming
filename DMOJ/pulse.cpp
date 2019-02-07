#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, s, t;
    scanf("%i%i%i", &n, &s, &t);
    int cnt = 0, a;
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        if (s <= a*2 && a*2 <= t)
            cnt++;
    }
    cout<<cnt<<endl;
}
