import sys
n = int(input())
v = sys.stdin.read().split('\n\n')
for x in v:
    dic = {}
    cnt = 1
    for a in x.split('\n'):
        for b in a.split():
            if b in dic:
                print(dic[b], end=" ")
            else:
                print(b, end=" ")
                dic[b] = cnt
                cnt += 1
        print()
