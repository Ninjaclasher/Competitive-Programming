#include <bits/stdc++.h>
 
using namespace std;
 
const long long MOD = 1000000007;
 
vector<vector<long long>> arr(55, vector<long long>(55));
 
int n;
 
vector<vector<long long>> mult(vector<vector<long long>> &a, vector<vector<long long>> &b)
{
    vector<vector<long long>> ret(55, vector<long long>(55));
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            for (int z = 0; z < n; z++)
                ret[x][z] = (ret[x][z] + a[x][y] * b[y][z]) % MOD;
    return ret;
}
 
int main()
{
    long long k;
    scanf("%i%lli", &n, &k);
    vector<vector<long long>> ret(55, vector<long long>(55));
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            scanf("%lli", &arr[x][y]), ret[x][y] = arr[x][y];
    --k;
    while (k)
    {
        if (k&1)
            ret = mult(ret, arr);
        arr = mult(arr, arr);
        k>>=1;
    }
    long long ans = 0;
    for (auto &x : ret)
        for (auto &y : x)
            ans = (ans + y)%MOD;
    printf("%lli\n", ans);
}
