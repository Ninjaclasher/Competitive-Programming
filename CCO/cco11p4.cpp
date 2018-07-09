#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, a, c = 0;
    vector<int> exist (1000000);
    set<int> aa;
    unordered_map<int, int> bb;
    scanf("%i%i", &n, &a);
    aa.insert(a);
    bb[a] = c++;
    while (--n)
    {
        scanf("%i", &a);
        auto it = aa.upper_bound(a);
        if (it != aa.begin()) it--;
        if (*it >= a) 
        {
            printf("NO");
            return 0;
        }
        if (exist[bb[*it]] == 1) 
            aa.erase(it);
        exist[bb[*it]]++;
        aa.insert(a);
        bb[a] = c++;
    }
    printf("YES");
    return 0;
}
