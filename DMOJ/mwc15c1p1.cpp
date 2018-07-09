#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, m, s, t = 0, c = 0;
    scanf("%i", &n);
    vector<int> aa;
    while (n--)
    {
        scanf("%i%i", &m, &s);
        aa.push_back(m*60 + s);
    }
    sort(aa.begin(), aa.end());
    scanf("%i%i", &m, &s);
    s += m*60;
    while (t <= s && c < aa.size())
        t += aa[c++];
    c -= t > s;
    printf("%i", c);
    return 0;
}
