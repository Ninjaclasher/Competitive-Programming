#include <bits/stdc++.h>

using namespace std;

int arr[2000001], m[21];

int main()
{
    int p, q, n, a;
    scanf("%i%i%i", &p, &q, &n);
    fill(m, m+21, 1);
    for (int x = p; x >= 0; m[x-1] = m[x]*q, x--);
    while (n--)
    {
        int b = 0;
        for (int y = 1; y <= p; b += m[y]*(q-a-1), y++)
            scanf("%i", &a);
        arr[b]++;
    }
    for (int x = 1; x <= p; x++)
        for (int y = m[x]; y < m[0]; y++)
            if (y/m[x-1] == (y-m[x])/m[x-1])
                arr[y] += arr[y-m[x]];
    scanf("%i", &n);
    while (n--)
    {
        int b = 0;
        for (int y = 1; y <= p; b += m[y]*(q-a-1), y++)
            scanf("%i", &a);
        printf("%i\n", arr[b]);
    }
}
