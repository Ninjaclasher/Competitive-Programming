n, m, a, b, c = map(int, input().split())

X = list(map(int, input().split()))
Y = list(map(int, input().split()))

for x in Y:
    m += [a, -b][1-X[x - 1]]

print(m)
