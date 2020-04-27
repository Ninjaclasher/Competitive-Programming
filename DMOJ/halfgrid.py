import math

w, h, x = map(int, input().split())
w -= 1
h -= 1

xx = [tuple(map(int, input().split())) for i in range(x)]

MOD = 10**9+7

def fac(n):
    ret = 1
    for i in range(2, n+1):
        ret = ret * i % MOD
    return ret

def choose(n, k):
    return fac(n) * pow(fac(k), MOD-2, MOD) * pow(fac(n-k), MOD-2, MOD) % MOD

def run(a, b):
    return choose(a + b, a)

def pr(v):
    print(v % MOD)

def cancer1(a, b, ww, hh):
    return run(a - 1, b - 1) * run(ww - a + 1, hh - b + 1)

def cancer():
    ret = run(w, h)
    if xx[0][0] > xx[1][0]:
        xx[0], xx[1] = xx[1], xx[0]

    ret -= cancer1(xx[0][0], xx[0][1], w, h)
    ret -= cancer1(xx[1][0], xx[1][1], w, h)
    if xx[0][1] <= xx[1][1]:
        ret += run(xx[0][0] - 1, xx[0][1] - 1) * run(xx[1][0] - xx[0][0], xx[1][1] - xx[0][1]) * run(w - xx[1][0] + 1, h - xx[1][1] + 1)
    return ret


if x == 0:
    pr(run(w, h))
elif x == 1:
    pr(run(w, h) - cancer1(xx[0][0], xx[0][1], w, h))
elif x == 2:
    pr(cancer())
