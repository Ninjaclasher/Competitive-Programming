#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int K, b, countl, countr, l, r, ans;
    vector<int> v;
    bool alloff = false;
    scanf("%i", &K);
    for(int x = 0; x < K; x++) 
    {
        scanf("%i", &b);
        v.push_back(b);
    }
    while(!alloff) 
    {
        countl = countr = 0;
        for(int x = 0; x < K; x++) 
        {
            if(x == K-1) 
            {
                countl = 100;
                break;
            }
            if(v[x] == 1) 
            {
                countl++;
                if(!v[x+1]) 
                {
                    l = x+1;
                    break;
                }
            }
        }
        if (countl == 0)
            countl = 100;
        for(int x = K-1; x >= 0; x--) 
        {
            if(!x) 
            {
                countr = 100;
                break;
            }
            if(v[x] == 1) 
            {
                countr++;
                if(!v[x-1]) 
                {
                    r = x - 1;
                    break;
                }
            }
        }
        if(!countr)
            countr = 100;
        if (countl <= countr)
            v[l] = 1;
        else
            v[r] = 1;
        ans++;
        for (int z = 6; z > 2; z--)
        {
            for (int x = 0; x < K-z; x++)
            {
                for (int y = 0; y <= z; y++)
                {
                    if (v[x+y] != 1)
                        goto label;
                }
                for (int o = x; o <= x+z; o++)
                    v[o] = 0;
                label:;
            }
        }
        alloff = true;
        for(int x = 0; x < K; x++) 
            if(v[x] == 1) 
                alloff = false;
    }
    printf("%i", ans);
}
