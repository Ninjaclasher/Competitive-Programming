import math

p = int(input())
q = int(input()) - 0.5
w = int(input())

s = max(0, math.ceil(100 * (q - p) / w + p))

print('DROP THE COURSE' if s > 100 else s)
