#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main()
{
    int n;
    double k, t = 0;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        cin >> k;
        t += k;
        t=fmod(t, 360);
    }
    cout <<fmod(t, 360);
    return 0;
}
