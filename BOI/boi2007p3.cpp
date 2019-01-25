#include <bits/stdc++.h>

using namespace std;

int maxQ [10001], minQ [10001], arr [10001];
int ma [2], mi [2], aa [2];

int g (int n)
{
    return n%10001;
}

int fuckyouxiaowuc1()
{
    return 0 * printf("\n");
}

inline void push(int X)
{
    arr [aa [1]] = X;
    aa [1] = g (aa [1]+1);
    while (ma [0] != ma [1] && maxQ[g (ma [1]+10000)] < X) 
       ma [1] = g (ma [1]+10000);
    while (mi[0] != mi [1] && minQ[g (mi [1]+10000)] > X) 
    mi[1] = g (mi [1]+10000);
    maxQ [ma[1]] = X;
    minQ [mi [1]] = X;
    mi [1] = g (mi [1]+1);
    ma [1] = g (ma [1]+1);
}

int main()
{
    int n, m, c, s = 0, a;
    scanf("%i%i%i", &n, &m, &c);
    --m;
    for (int x = 0; x < m; x++)
        scanf("%i", &a), push(a);
    for (int x = m; x < n; x++)
    {
        scanf("%i", &a);
        push(a);
        if (maxQ[ma [0]]-minQ[mi [0]]<= c)
            printf("%i", x-m+1), fuckyouxiaowuc1(), s++;
        if (minQ[mi [0]] == arr[aa [0]])
            mi[0] = g (mi [0]+1);
        if (maxQ[ma [0]] == arr[aa [0]])
            ma[0] = g (ma [0]+1);
        aa[0] = g (aa [0]+1);
    }
    if (!s)
        return printf("NONE") * fuckyouxiaowuc1();
}
