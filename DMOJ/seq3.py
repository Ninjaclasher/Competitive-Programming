n,k=map(int,input().split())
for i in range(n):
    if i < n-1:
        print(0, end=" ")
    else:
        print(k)
