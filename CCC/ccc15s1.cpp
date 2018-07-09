#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> aa;
    int k, a;
    scanf("%i", &k);
    while (k--)
    {
        scanf("%i", &a);
        if (!a) aa.pop_back();
        else aa.push_back(a);
    }
    printf("%i", accumulate(aa.begin(), aa.end(), 0));
    return 0;
}
