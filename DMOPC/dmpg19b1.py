n = int(input())
c = sum(map(int, input().split()))
if c > 200:
    print("Over maximum capacity!")
else:
    print(200 - c)
