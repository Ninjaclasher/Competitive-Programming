#include <bits/stdc++.h>

using namespace std;

long long act[2000000], arr[2][2000000];
int m[10], a[10];

int main()
{
    int n, id = 1, nid = 0;
    scanf("%i", &n);
    fill(m, m+10, 1);
    for (int x = 1; x <= n; x++)
        scanf("%i", &a[x]);
    for (int x = n; x > 0; x--)
        m[x-1] = m[x]*a[x];
    for (int x = 0; x < m[0]; x++)
        scanf("%lli", &arr[0][x]), act[x] = arr[0][x];
    for (int i = 1; i <= n; id^=1, nid^=1, i++)
    {
        for (int x = 0; x < m[0]; x++)
        {
            arr[id][x] = arr[nid][x];
            if (x-m[i] >= 0 && x/m[i-1] == (x-m[i])/m[i-1])
                arr[id][x] += arr[nid][x-m[i]];
            if (x/m[i-1] == (x+m[i])/m[i-1])
                arr[id][x] += arr[nid][x+m[i]];
        }
    }
    for (int x = 0; x < m[0]; x++)
        printf("%lli\n", arr[nid][x]-act[x]);
}
