def f(s):
    return str(sum(map(int,s)))
t = int(input())
for i in range(t):
    n = input()
    while len(n) > 1:
        n = f(n)
    print(n)
