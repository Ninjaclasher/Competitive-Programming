#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> bit(2, vector<int>(500050));

int query(int n)
{
    int sum = 0, sum1 = 0;
    for (int x = n; x > 0; x -= x&-x)
        sum += bit[0][x];
    for (int x = bit[0].size()-n; x > 0; x -= x&-x)
        sum1 += bit[1][x];
    return min(sum, sum1);
}

void update(int n)
{
    for (int x = n; x < bit[1].size(); x += x&-x)
        bit[0][x]++;
    for (int x = bit[1].size()-n; x < bit[1].size(); x += x&-x)
        bit[1][x]++;
}

int main() 
{
    int n, a;
    long long s = 0;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i", &a);
        s += query(a);
        update(a);
    }
    printf("%lli", s);
    return 0;
}
