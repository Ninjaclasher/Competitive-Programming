n, c = map(int, input().split())

for i in range(n):
    s, x = input().split()
    print(s + ' will', end='')
    if int(x) <= c:
        print(' not', end='')
    print(' advance')
