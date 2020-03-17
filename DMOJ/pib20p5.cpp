#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int arr[MAXN][MAXN];

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        for (int y = 1; y < n; y++)
        {
            scanf("%i", &arr[x][y]);
            arr[x][y] += arr[x][y-1];
        }
    }
    int med = (n-1) >> 1;
    vector<int> meds(n), cur(n);
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
            cur[x] = arr[x][y];
        sort(cur.begin(), cur.end());
        meds[y] = cur[med];
    }
    sort(meds.begin(), meds.end());
    printf("YES\n");
    for (int x = 0; x < n; x++)
        printf("%i%c", -meds[med], x == n-1 ? '\n' : ' ');
}
