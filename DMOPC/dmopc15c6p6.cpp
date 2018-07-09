#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, K, a, b; 
    bitset<1502> adj[1502];
    scanf("%i%i%i", &N, &M, &K);
    while (M--)
    {
        scanf("%i%i", &a, &b);
        adj[b][a]=adj[a][b]=1;
    }
    for(int i = 1; i <= N; i++)
    {
        bitset<1502> cnt, tmp;
        cnt[i]=1;
        for (int k = 1; k <= K; k++)
        {
            tmp = cnt;
            for (int j = 1; j <= N; j++)
                if(tmp[j]) 
                    cnt|=adj[j];
        }
        printf("%d\n", cnt.count());
    }
}
