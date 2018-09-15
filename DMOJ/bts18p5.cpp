#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
long long arr[2005], dp[2005][2005];

int main()
{
    int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld", arr + i);

	for (int n = 0; n <= N; n++)
		dp[0][n] = 1;

	for (int k = 1; k <= N; k++)
		for (int n = k; n <= N; n++)
			dp[k][n] = (dp[k][n - 1] + arr[n] * dp[k - 1][n - 1] % MOD) % MOD;

	for (int i = 1; i <= N; i++)
        printf("%lld%c", (dp[i][N] + MOD) % MOD, i==N ? '\n' : ' ');
}
