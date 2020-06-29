t = int(input())

def prime(n):
    if n == 1:
        return False
    for i in range(2, int(n**0.5+1)):
        if n % i == 0:
            return False
    return True

def solve():
    a, b = map(int, input().split())

    for i in range(b):
        sa = str(a)
        if prime(a):
            a *= 11
        elif int(a**0.5)**2 == a:
            a += int(sa[::-1])
        elif sa == sa[::-1]:
            a = int(sa + '4')
        elif sa.startswith('2'):
            a = int('5' + sa)
        elif '7' in sa:
            a //= 10
        elif a % 6 == 0:
            a = int(sa[1:] or '')
        elif len(sa) % 2 == 0:
            l = len(sa)
            a = int(sa[:l // 2] + '1' + sa[l // 2:])
        elif len(str(a)) % 2 == 1:
            a += 231
    print(a) 

for _ in range(t):
    solve()
