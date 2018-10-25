dp = [0]*1010

n = int(input())
dp[1] = 1
for x in range(2, n+1):
    dp[x] = x
    for y in range(1, x):
        dp[x] = max(dp[x], dp[x-y]*y)
print(dp[n]%1000000007)
