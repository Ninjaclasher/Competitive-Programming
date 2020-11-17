r = int(input())

class Round:
    def __init__(self, n, m, g):
        self.n = n
        self.m = m
        self.g = g


rounds = []
for i in range(r):
    n, m = map(int, input().split(' '))
    g = list(map(int, input().split(' ')))
    rounds.append(Round(n, m, g))


possibility = []


for a in range(1, 16):
    for b in range(a + 1, 16):
        for c in range(b + 1, 16):
            _cur = {a, b, c}
            for r in rounds:
                common = len(set(r.g) & _cur)
                if common != r.m:
                    break
            else:
                possibility.append(sorted(_cur)) 


if len(possibility) == 0:
    print(-1)
elif len(possibility) == 1:
    print(*possibility[0])
else:
    print(len(possibility))
