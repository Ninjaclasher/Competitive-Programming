#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a = 0;
    string name;
    cin >> n;
    char f[n];
    for (int x = 0; x < n; x++)
    {
        cin >> name;
        f[x] = name[0];
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = x; y < n; y++)
        {
            if (f[x] == f[y])
                a++;
            else
                break;
        }
    }
    cout << a;
    return 0;
}
