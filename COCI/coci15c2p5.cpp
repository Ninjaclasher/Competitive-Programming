#include <bits/stdc++.h>

using namespace std;

vector<long long> bit(1000006);

void update(int i, int v)
{
    for (; i < bit.size(); i += i&-i)
        bit[i] += v;
}

long long query(int i)
{
    long long sum = 0;
    for (; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

int main()
{
    int n, p;
    scanf("%i", &n);
    vector<pair<long long,int>> arr(n+1);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &arr[x].first), arr[x].second = x;
    scanf("%i", &p);
    for (int x = 1; x <= n; x++)
        arr[x].first += arr[x-1].first - p;
    sort(arr.begin(),arr.end());
    long long aa = 0;
    for (auto &x : arr)
        aa += query(x.second+1), update(x.second+1, 1);
    printf("%lli", aa);
}
