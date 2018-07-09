#include <bits/stdc++.h>

using namespace std;

static inline double angle(int x1, int y1, int x2, int y2)
{
    return round(acos(abs(x2-x1)/sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))) * 1000000000)/1000000000.0;
}

vector<int> bit(200001, 0);

void update(int i)
{
    for (; i < bit.size(); i += i&-i)
        bit[i]++;
}

int query(int i)
{
    int sum = 0;
    for (; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

int main() 
{
    int n, xx, a, b;
    scanf("%i%i", &n, &xx);
    vector<pair<double, double>> an(n);
    set<double> yy;
    map<double, int> mp;
    for (auto &x : an)
    {
        scanf("%i%i", &a, &b);
        x = make_pair(angle(a, b, 0, 0), angle(a, b, xx, 0));
        yy.insert(x.second);
    }
    a = 0;
    for (auto &x : yy)
        mp[x] = ++a;
    sort(an.rbegin(), an.rend());
    long long tDis = 0;
    for (auto &x : an)
    {
        a = 200000-mp[x.second];
        long long d = query(a);
        tDis += d*d;
        update(a);
    }
    printf("%lli", tDis);
    return 0;
}
