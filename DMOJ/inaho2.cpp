#include <bits/stdc++.h>

using namespace std;

int arr[10000001];
short act[10000001];
int n, q, a, b;
int len[10], idx[2][10], mm[11];

void update(int nn, int pos, int val)
{
    if (nn == n)
        arr[pos]+=val;
    else
        for (int x = idx[0][nn]; x <= len[nn]; x+=x&-x)
            update(nn+1, pos + (x-1)*mm[nn], val);
}

int query(int nn, int pos)
{
    if (nn == n)
        return arr[pos];
    int sum = 0;
    for (int x = idx[1][nn]; x > 0; x-=x&-x)
        sum += query(nn+1, pos + (x-1) * mm[nn]);
    for (int x = idx[0][nn]; x > 0; x-=x&-x)
        sum -= query(nn+1, pos + (x-1) * mm[nn]);
    return sum;
}

int main()
{
    scanf("%i%i", &n, &q);
    memset(len,1,sizeof(len));
    memset(idx,1,sizeof(idx));
    mm[0]=1;
    for (int x = 0; x < n; mm[x+1]=mm[x]*len[x], x++)
        scanf("%i", &len[x]);

    while (q--)
    {
        scanf("%i", &a);
        for (int x = 0; x < n; x++)
            scanf("%i", &idx[0][x]);
        if (a == 1)
        {
            scanf("%i", &b);
            int pos = 0;
            for (int x = 0; x < n; x++)
                pos += (idx[0][x]-1)*mm[x];
            update(0,0,b-act[pos]);
            act[pos] = b;
        }
        else
        {
            for (int x = 0; x < n; idx[0][x]--, x++)
                scanf("%i", &idx[1][x]);
            printf("%i\n", query(0,0));
        }
    }
}
