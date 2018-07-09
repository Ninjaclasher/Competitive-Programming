#include <bits/stdc++.h>

using namespace std;

vector<int> bit(200000);

void update(int n)
{
    for (; n < bit.size(); n += n & -n)
        bit[n]++;
}

int query(int n)
{
    int sum = 0;
    for (; n > 0; n -= n&-n)
        sum += bit[n];
    return sum;
}

int main() 
{
    int t;
    long double ss = 0;
    scanf("%i", &t);
    vector<int> aa(t);
    set<int> s;
    map<int,int> mp;
    for (auto &x : aa)
        scanf("%i", &x), s.insert(x);
    int i = 0;
    for (auto &x : s)
        mp[x] = ++i;
    for (int y = 0; y < aa.size(); y++)
    {
        auto x = aa[y];
        ss += y - query(mp[x]) + 1;
        update(mp[x]);
    }
    printf("%.2Lf", floor(ss/t*100)/100.0);
    return 0;
}
