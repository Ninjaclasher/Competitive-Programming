a = list(map(int, input().split()))
b = list(map(int, input().split()))
print(max(sum(a) - min(a), sum(b) - min(b)))
