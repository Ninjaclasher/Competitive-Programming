#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    string s;
    cin>>s;
    long long cntw = 0, cnta = 0, cntc = 0;
    long long ans = 0;
    long long cntww = 0, cntc_allhere = 0, cntc_a = 0;
    for (int x = 0; x < n; x++)
    {
        if (s[x] == 'W')
            cntw++;
        else if (s[x] == 'A')
            cntww += cntw, cnta++;
        else if (s[x] == 'C')
            cntc_allhere += cntww, cntc_a += cnta, cntc++;
    }
    for (int x = 0; x < k; x++)
    {
        ans += cntc_allhere;
        ans %= MOD;
        ans += cntw * x % MOD * cntc_a % MOD;
        ans %= MOD;
        ans += cntww * x % MOD * cntc % MOD;
        ans %= MOD;
        ans += cntw * (x * (long long)(x - 1) / 2) % MOD * cnta % MOD * cntc % MOD;
        ans %= MOD;
    }
    cout << ans << endl;    
}
