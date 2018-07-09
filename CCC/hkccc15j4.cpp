#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, ll, s, t, l = 0;
    scanf("%i%i", &ll, &n);
    vector<pair<int,int>> aa;
    while (n--)
    {
        scanf("%i%i", &s, &t);
        aa.push_back(make_pair(s, t));
    }
    aa.push_back(make_pair(0,0));
    aa.push_back(make_pair(ll, ll));
    sort(aa.begin(), aa.end());
    for (int x = 0; x < aa.size()-1; x++)
    {
        while (aa[x].second > aa[x+1].second) aa.erase(aa.begin()+x+1);
        l = max(l, aa[x+1].first - aa[x].second);
    }
    printf("%i\n", l);
    return 0;
}
