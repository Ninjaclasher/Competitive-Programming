import sys
n = sys.stdin.read().split('\n')
arr = []
cur = []
for x in n:
    if "=" in x:
        arr.append(cur)
        cur = []
    else:
        x = x.strip('|')
        cur.append(list(x))

for grid in arr:
    xx = len(grid)
    yy = len(grid[0])
    cnt = [0] * yy
    for y in range(yy):
        for x in range(xx):
            cnt[y] += grid[x][y] == 'O'
    mi = min(cnt)
    for y in range(yy):
        cnt[y] -= mi
    for x in range(xx):
        grid[x] = [' ']*yy
    for y in range(yy):
        for x in range(cnt[y]):
            grid[xx-x-1][yy-y-1] = 'O' 
    for x in grid:
        print('|'+''.join(x)+'|')
    print('|' + "="*yy + '|')
