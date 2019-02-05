def f(x):
    return sum(map(int,x))
n = input().split('-')
if f(n[0]) == f(n[1]) == f(n[2]):
    print("Goony!")
else:
    print("Pick up the phone!")
