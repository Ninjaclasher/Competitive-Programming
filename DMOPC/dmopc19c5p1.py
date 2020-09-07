n, m = map(int, input().split())
has = set(input().strip() for i in range(n))
ans = 0
for i in range(m):
    t = int(input())
    v = [input().strip() for j in range(t)]
    ans += all(x in has for x in v)

print(ans)
