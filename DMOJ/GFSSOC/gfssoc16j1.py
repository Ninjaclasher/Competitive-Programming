c, n = map(int, input().split())

mp = ['TOK', 'English', 'Chemistry', 'Math']

arr = [mp.index(input()) + 1 for x in range(c)]

arr.sort()

for i, j in enumerate(arr):
    n -= j
    if n < 0:
        print('Go to Metro')
        print(i)
        break
else:
    print('YEA BOI')

