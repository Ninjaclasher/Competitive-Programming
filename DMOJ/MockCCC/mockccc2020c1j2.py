a = int(input())
b = int(input())
c = int(input())
ma = 0
for x in range(c+1):
    for y in range(c+1):
        if x+y <= c:
            ma = max(ma, a * x + b * y)
print(ma)
