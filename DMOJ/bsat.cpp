#include <bits/stdc++.h>

using namespace std;

int cur[2][40000000];
int idx[2] = {1, 1};
vector<long long> val;

int hibit(int n) {
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    return n - (n >> 1);
}

int main()
{
    int n;
    long long k, s = 0;
    scanf("%i%lli", &n, &k);
    val.resize(n/2);
    for (auto &x : val)
        scanf("%lli", &x);
    for (int x = 1; x < (1<<val.size()); x++)
        cur[0][idx[0]++] = cur[0][x-hibit(x)]+val[(int)log2(hibit(x))];
    if (n&1)
        val.push_back(0);
    for (auto &x : val)
        scanf("%lli", &x);
    for (int x = 1; x < (1<<val.size()); x++)
        cur[1][idx[1]++] = cur[1][x-hibit(x)]+val[(int)log2(hibit(x))];
    sort(cur[0], cur[0]+idx[0]);
    sort(cur[1], cur[1]+idx[1]);
    for (int x = 0, y = idx[1]-1; x < idx[0] && y >= 0; x++)
    {
        while (y >= 0 && cur[0][x]+cur[1][y] > k) y--;
        s += y+1;
    }
    printf("%lli\n", s);
}
