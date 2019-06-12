n, p = map(int, input().split())
names = [input() for x in range(n)]
scores = [0] * n
for i in range(p):
    j = list(map(int, input().split()))
    for k in range(n):
        scores[k] += j[k]
p = sorted(zip(scores, names), reverse=True)
for i in range(n):
    print(str(i + 3) + '.', p[i][1])
