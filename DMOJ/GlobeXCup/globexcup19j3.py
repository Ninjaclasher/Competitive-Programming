n, k = map(int, input().split())

arr = []
for x in range(n):
    name, size = input().split()
    arr.append((int(size), name))

arr.sort()

good = []

for x in range(n):
    if (x+1 < n and arr[x+1][0] - arr[x][0] <= k) or (x > 0 and arr[x][0] - arr[x-1][0] <= k):
        continue
    good.append(arr[x][1])

print(*sorted(good))
