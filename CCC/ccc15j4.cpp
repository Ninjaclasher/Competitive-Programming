#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> aa (105), bb (105), cc (105);
    int n, m, t = 0;
    char c; 
    scanf("%i", &m);
    while (m--)
    {
        scanf(" %c%i", &c, &n);
        if (c == 'S')
            aa[n] += t-cc[n], bb[n]=1;
        else if (c == 'R')
            cc[n]=t, bb[n]=-1;
        else t+=n-2;
        t++;
    }
    for (int x = 0; x < 105; x++)
        if (bb[x])
            printf("%i %i\n", x, (bb[x] > 0 ? aa[x] : bb[x]));
}
