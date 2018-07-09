#include <stdio.h>

#define swap(a,b) ({__typeof(a) _ = a;a = b;b = _;})

unsigned long long arr[1000005];

int main()
{
    for (int x = 2; x < 1000005; x++)
        arr[x] = x+1;
    arr[0] = 1;
    arr[1] = 0;
    long long m, cur=1, free=2, prevcur = 0, lastfree = 1000004, a;
    char t;
    scanf("%lli", &m);
    while (m--)
    {
        scanf(" %c", &t);
        switch(t)
        {
            case '<':;
                swap(cur, prevcur);
                prevcur ^= arr[cur] & ((1<<20)-1);
                break;
            case '>':;
                swap(cur, prevcur);
                cur ^= arr[prevcur] & ((1<<20)-1);
                break;
            case '=':;
                scanf("%lli", &a);
                if (a < 0)
                    a = (-a)|(1LL<<43);
                arr[cur] &= (1<<20)-1;
                arr[cur] |= a<<20;
                break;
            case '+':;
                scanf("%lli", &a);
                if (a < 0)
                    a = (-a)|(1LL<<43);
                int new = free;
                free = arr[free];
                arr[cur] ^= new ^ prevcur;
                arr[prevcur] ^= new ^ cur;
                arr[new] = (cur ^ prevcur) | (a<<20);
                cur = new;
                break;
            case '-':;
                int next = (arr[cur] & ((1<<20)-1)) ^ prevcur;
                arr[prevcur] ^= cur ^ next;
                arr[next] ^= cur ^ prevcur;
                arr[cur] = 0;
                arr[lastfree] = cur;
                lastfree = cur;
                cur = next;
                break;
            case '!':;
                long long p = arr[cur]>>20;
                if (p>>43&1)
                     p = -(p^(1LL<<43));
                printf("%lli\n",p);
                break;
        }
    }
}
