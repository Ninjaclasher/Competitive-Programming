import sys
arr = sys.stdin.read().split('\n') 
for x in range(10):
    arr[x] = arr[x].split()

def defined(v):
    try:
        int(v)
    except:
        return False
    else:
        return True

for k in range(1000):
    for i in range(10):
        for j in range(9):
            if defined(arr[i][j]):
                continue
            else:
                ss = 0
                for x,y in arr[i][j].split('+'):
                    v = arr[ord(x)-ord('A')][int(y)-1]
                    if defined(v):
                        ss += int(v)
                    else:
                        break
                else:
                    arr[i][j] = ss
for x in arr:
    x = [str(y) if defined(y) else '*' for y in x]
    print(' '.join(map(str, x)))
