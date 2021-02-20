def sgn(n):
    return 0 if not n else n // abs(n)

b = int(input())
assert 80 <= b <= 200

p = 5 * b - 400
print(p)
print(sgn(100 - p))
