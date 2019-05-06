a = input().split()
l = [i for i, j in enumerate(a, 1) if j == 'L']
r = [i for i, j in enumerate(a, 1) if j == 'R']
for i, j in zip(l, r):
    print(i, j)
