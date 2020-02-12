#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> neg, pos;
    int ze = 0;
    int a;
    while (n--)
    {
        scanf("%i", &a);
        if (a < 0)
            neg.push_back(a);
        else if (a > 0)
            pos.push_back(a);
        else
            ze++;
    }
    sort(neg.begin(), neg.end());
    int cur = 1;
    for (auto &x : pos)
        cur *= x;
    for (int x = 0; x+1 < neg.size(); x += 2)
        cur *= neg[x] * neg[x+1];
    if (pos.empty() && neg.size() <= 1)
        cur = ze ? 0 : neg[0];
    printf("%i\n", cur);
}
