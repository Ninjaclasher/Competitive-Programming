#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

int dp[MAXN][2][2];
vector<int> arr;
int n;

bool noncreasing(int a, int b, int c)
{
    return (arr[a] < arr[b]) == (arr[b] < arr[c]);
}

int f(int i, int flip)
{
    int pos[2] = {i, n-i+1};
    return pos[flip];
}

int main()
{
    scanf("%i", &n);
    if (n <= 2) // edge case
        return 0 * printf("1\n");
    arr.resize(n+1);
    for (int x = 1; x <= n; x++)
        scanf("%i", &arr[x]);
    if (n&1)
    {
        arr.insert(arr.begin() + n/2+1, arr[n/2+1]);
        n++;
    }
    for (int x = 3; x <= n/2; x++)
    {
        for (int a = 0; a <= 1; a++)
        {
            for (int b = 0; b <= 1; b++)
            {
                dp[x][a][b] = INT_MAX;
                for (int c = 0; c <= 1; c++)
                    dp[x][a][b] = min(dp[x][a][b], dp[x-1][b][c] + !noncreasing(f(x, a), f(x-1, b), f(x-2, c)) +
                                                                   !noncreasing(f(x, a^1), f(x-1, b^1), f(x-2, c^1)));
            }
        }
    }
    int ans = INT_MAX;
    for (int a = 0; a <= 1; a++)
    {
        for (int b = 0; b <= 1; b++)
        {
            int mod = 0;
            int x = n/2;
            bool b1 = noncreasing(f(x-1, b), f(x, a), f(x, a^1)),
                 b2 = noncreasing(f(x, a), f(x, a^1), f(x-1, b^1));
            if (b1 && b2)
                mod--;
            else if (!b1 && !b2)
                mod++;
            ans = min(ans, dp[x][a][b] + mod);
        }
    }
    printf("%i\n", ans+2);
}
