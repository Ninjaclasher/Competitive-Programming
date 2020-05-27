a = [0] + list(map(int, input().split()))

b = ['12', '13', '14', '23', '24', '34', '123', '124', '134', '234', '1234']

def avg(a):
    return sum(a) / len(a)

for x in b:
    print(avg([a[int(y)] for y in x]))
