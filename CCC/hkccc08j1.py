c = int(input())
def f(a, b):
    return a*b
a = max(f(*map(int,input().split())) for x in range(c))
c = int(input())
b = max(f(*map(int,input().split())) for x in range(c))
if a > b:
    print("Casper")
elif a < b:
    print("Natalie")
else:
    print("Tie")
