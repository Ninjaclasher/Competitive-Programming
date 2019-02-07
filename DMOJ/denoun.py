import string
n=int(input())
for i in range(n):
    print(sum(a[0] in string.ascii_uppercase for a in input().split()))
    
