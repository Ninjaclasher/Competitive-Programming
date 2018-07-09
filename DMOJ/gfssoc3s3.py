n = input()
if len(n) > 2:
    print(999999998)
else:
    if int(n)&1 == 0:
        print((2*(10**(int(n)>>1)-1)) % 1000000000)
    else:
        print((11*10**(int(n)>>1)-2) % 1000000000)
