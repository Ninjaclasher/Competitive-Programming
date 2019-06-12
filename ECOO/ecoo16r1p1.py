def solve():
    a, b, c, d = map(int, input().split())
    cnt = 0
    for i in range(int(input())):
        aa, bb, cc, dd = map(int, input().split())
        if aa * a + bb * b + cc * c + dd * d >= 5000:
            cnt += 1
    print(cnt)

for i in range(10):
    solve()
