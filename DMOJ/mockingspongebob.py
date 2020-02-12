import string

n = int(input())
for i in range(n):
    s = input()
    t = ''
    cur = 0
    for x in s:
        if x in string.ascii_letters:
            t += x.upper() if cur else x.lower()
            cur ^= 1
        else:
            t += x
    print(t)
