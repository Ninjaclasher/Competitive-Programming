def good(x):
    x = x[::-1]
    return (sum(sum(map(int, str(int(y) * 2))) for y in x[1::2]) + sum(map(int, x[::2]))) % 10 == 0

def calc(x):
    for v in range(10):
        if good(x + str(v)):
            return str(v)
    assert False

for i in range(5):
    arr = input().split()
    ret = ''
    for x in arr:
        ret += calc(x)
    print(ret)
