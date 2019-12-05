from collections import defaultdict
n = int(input())
mp = defaultdict(int)
for x in list(map(int, input().split())):
    mp[x] += 1
ma = 0
arr = []
for x, y in mp.items():
    if ma < y:
        ma = y
        arr = [x]
    elif ma == y:
        arr.append(x)
print(*sorted(arr))
