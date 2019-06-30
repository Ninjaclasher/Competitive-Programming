n = int(input())
arr = sorted(input() for x in range(n))
v = [[] for x in range(26)]
for x in arr:
    v[ord(x[0]) - ord('a')].append(x)
for x in v:
    if len(x) > 0:
        print(', '.join(x))
