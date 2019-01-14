def gcd(a, b):
    if not a:
        return b, 0, 1
    g, xx, yy = gcd(b%a, a)
    return g, yy - b//a*xx, xx

n, m = map(int,input().split())
g, x, y = gcd(n, m)
print(x%m)
