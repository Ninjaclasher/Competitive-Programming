import sys
a = list(map(int,sys.stdin.read().split()))
a.sort()
if a[0] + a[1] <= a[2]:
    print("Maybe I should go out to sea...")
else:
    print("Huh? A triangle?")
