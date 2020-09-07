from collections import defaultdict

for i in range(10):
    cnt = defaultdict(int)

    while (s := input().strip()) != 'end of box':
        cnt[s] += 1

    def f(x):
        return (x + 6) // 7 * 13

    print(sum(f(cnt[x]) for x in ['orange', 'blue', 'green', 'yellow', 'pink', 'violet', 'brown']) + cnt['red'] * 16)
