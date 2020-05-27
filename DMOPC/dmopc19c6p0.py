a = list(map(int, input().split()))
a.sort()

print(['yes', 'no'][a[0] + a[1] <= a[2]])
