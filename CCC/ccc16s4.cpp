#include <bits/stdc++.h>
 
using namespace std;
 
int riceBalls[400];
int counts[400][400];

inline bool combinable(int s, int e) {return (s == e ? true : counts[s][e] != -1);}
 
inline int count(int s, int e) {return (s == e ? riceBalls[s] : counts[s][e]);}
 
bool combineTwo(int fs, int le)
{
    for (int ls = fs+1; ls <= le; ls++)
        if (combinable(fs,ls-1) && combinable(ls,le))
            if (count(fs,ls-1) == count(ls,le))
                {counts[fs][le] = count(fs,ls-1) + count(ls,le); return true; }
    return false;
} 
     
void combineThree(int fs, int le)
{
    for (int ms = fs+1; ms < le; ms++)
        if (combinable(fs,ms-1))
            for (int ls = ms+1; ls <= le; ls++)
                if (combinable(ms,ls-1) && combinable(ls,le) && count(fs,ms-1) == count(ls,le))
                    {counts[fs][le] = count(fs,ms-1) + count(ms,ls -1) + count(ls,le); return; }
}
 
int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &riceBalls[x]);
        for (int y = 0; y < n; y++)
            counts[x][y] = -1;
    }
    for (int range = 2; range <= n; range++)
        for (int x = 0; x <= n-range; x++)
            if (!combineTwo(x,x + range - 1) && range > 2) combineThree(x,x + range - 1);
    int largest = 0;
    for (int x = 0; x < n; x++)
        for (int y = x; y < n; y++)
            largest = max(largest,count(x,y));
    printf("%i\n", largest);
    return 0;
}
