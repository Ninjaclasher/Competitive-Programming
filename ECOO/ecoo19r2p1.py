def solve():
    n = int(input())
    a = set()
    for i in range(n):
        s = input().lower()
        s = s.split('@')
        s[0] = s[0].replace('.', '')
        s[0] = s[0].split('+')[0]
        a.add(s[0] + '@' + s[1])
    print(len(a))

for i in range(10):
    solve()
