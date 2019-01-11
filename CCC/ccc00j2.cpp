#include <bits/stdc++.h>

using namespace std;

bool good(int n)
{
    string a = to_string(n);
    string b = a;
    reverse(b.begin(), b.end());
    for (int x = 0; x < b.size(); x++)
    {
        if (a[x] == '0' || a[x] == '1' || a[x] == '8')
        {
            if (a[x] != b[x])
                return false;
        }
        else if (a[x] == '9')
        {
            if (b[x] != '6')
                return false;
        }
        else if (a[x] == '6')
        {
            if (b[x] != '9')
                return false;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    int m, n;
    scanf("%i%i", &m, &n);
    int ans = 0;
    for (int x = m; x <= n; x++)
        if (good(x))
            ans++;
    printf("%i\n", ans);
}
