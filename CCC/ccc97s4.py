import sys
n = int(input())
v = sys.stdin.read().strip().split('\n\n')
for x in v:
    dic = {}
    cnt = 1
    for a in x.split('\n'):
        line = []
        for b in a.split():
            if b in dic:
                line.append(dic[b])
            else:
                line.append(b)
                dic[b] = cnt
                cnt += 1
        print(' '.join(map(str, line)))
    print()
