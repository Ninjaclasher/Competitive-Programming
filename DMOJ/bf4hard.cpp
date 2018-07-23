#include<bits/stdc++.h>
 
using namespace std; 
 
int base = 126, MOD = 101;

int search(string pat, string txt)
{
    int M = pat.length(), N = txt.length(), p = 0, t = 0, h = 1;
    for (int x = 1; x < M; x++)
        h = h * base % MOD;
    for (int x = 0; x < M; x++)
    {
        p = (p*base + pat[x]) % MOD;
        t = (t*base + txt[x]) % MOD;
    }
    for (int x = 0; x <= N-M; x++)
    {
        if (p == t)
        {
            bool found = true;
            for (int j = 0; j < M && found; j++)
                found &= txt[x+j] == pat[j];
            if (found)
                return x;
        }
        if (x < N-M)
            t = (((t - txt[x]*h) * base + txt[x+M]) % MOD + MOD) % MOD;
    }
    return -1;
}
 
int main()
{
    string txt, pat;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>txt>>pat;
    printf("%i\n", search(pat, txt));
}
