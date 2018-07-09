import sys
n = int(sys.stdin.readline())
prime = [True]*100002
prime[0] = False
prime[1] = False
for x in range(2, 400):
    if prime[x]:
        for y in range(x*x, 100002, x):
            prime[y] = False
a = [int(x) for x in sys.stdin.readline().split(' ')]
b = 0
for x in a:
    b += 1 if prime[x] else 0

print b
