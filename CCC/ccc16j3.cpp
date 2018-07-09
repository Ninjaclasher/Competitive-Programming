#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    int ma = 0;
    cin>>a;
    for (int x = 0; x < a.length(); x++)
    {
        reverse(b.begin(), b.end());
        b += a[x];
        reverse(b.begin(), b.end());
        string c = b, d = b;
        for (int y = 0; y < b.length(); y++)
        {
            reverse(c.begin(), c.end());
            if (c == d) ma = max(ma, (int)c.length());
            reverse(c.begin(), c.end());
            c.pop_back(), d.pop_back();
        }
    }
    printf("%i\n", ma);
    return 0;
}
