#include<bits/stdc++.h>
 
using namespace std; 
 
#define d 100000
 
int search(string pat, string txt, int q)
{
    int M = pat.length(), N = txt.length(), i, j, p = 0, t = 0, h = 1;
 
    for (i = 0; i < M-1; i++)
        h = (h*d)%q;
 
    for (i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }
 
    for (i = 0; i <= N - M; i++)
    {
 
        if ( p == t )
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
 
            if (j == M)
                return i;
        }
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
            if (t < 0)
            t = (t + q);
        }
    }
    return -1;
}
 
int main()
{
    string txt, pat;
    cin>>txt>>pat;
    int q = 101;
    printf("%i", search(pat, txt, q));
    return 0;
}
