n = int(input())
a = input().split()
b = input().split()
print(sum(a[i] == b[i] and (not i or a[i-1] != b[i-1]) for i in range(n)))
