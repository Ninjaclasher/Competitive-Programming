#include <bits/stdc++.h>

using namespace std;

int main()
{
    int y;
    scanf("%i", &y);
    vector<int> f;
    for (long long x = 2; x*x <= y; x++)
    {
        while (y%x == 0)
        {
            f.push_back(x);
            y /= x;
        }
    }
    if (y > 1)
        f.push_back(y);
    sort(f.begin(), f.end());
    for (auto &x : f)
        printf("%i\n", x);
}
