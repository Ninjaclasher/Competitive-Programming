n = int(input())
arr = list(map(int, input().split()))
s = sum(arr) // n
print(sum(s != x for x in arr))
