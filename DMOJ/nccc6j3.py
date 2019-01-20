t = int(input())
for i in range(t):
    a, b, n = map(int,input().split())
    for x in range(55):
        if (n - a*x) % b == 0 and a*x <= n:
            print("YES")
            break
    else:
        print("NO")
