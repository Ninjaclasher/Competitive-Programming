n = int(input())
assert 1 <= n <= 10**6
mp = [0] * 51
arr = list(map(int, input().split(' ')))
assert len(arr) == n
assert all(0 <= x <= 50 for x in arr)

for i in arr:
    mp[i] += 1
    
ma = 0
for i in range(len(mp)):
    if mp[ma] * ma < mp[i] * i:
        ma = i

print(ma)
