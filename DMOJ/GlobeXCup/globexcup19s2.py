def calc(f, x):
    xx = 1.0
    ret = 0.0
    for c in f:
        ret += c * xx
        xx *= x
    return ret

n = int(input())
f = list(map(int, input().split()))[::-1]
m = int(input())
g = list(map(int, input().split()))[::-1]
l, r = map(float, input().split())

if calc(f, l) < calc(g, l) or calc(f, r) > calc(g, r):
    f, g = g, f

while r - l > 1e-9:
    m = (l+r) / 2
    if calc(f, m) > calc(g, m):
        l = m
    else:
        r = m
print('{:.10f}'.format((l+r)/2))
