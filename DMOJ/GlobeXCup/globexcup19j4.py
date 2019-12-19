from collections import defaultdict

n, m, k = map(int, input().split())

mp = defaultdict(int)

for x in list(map(int, input().split())):
    mp[x] += 1

arr = sorted(mp.values(), reverse=True)

ans = 0

for x in arr:
    if k - x <= 0:
        ans += k * (k-1) // 2
        break
    else:
        ans += x*(x-1) // 2
        k -= x
print(ans)
