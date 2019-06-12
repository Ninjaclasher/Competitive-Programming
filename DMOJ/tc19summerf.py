a, b, c = map(int,input().split())
d, e, f = map(int, input().split())

print(max(abs(a-d), abs(b-e), abs(c-f)))
print(int((((a-d)**2 + (b-e)**2 + (c-f)**2)**0.5)))
print(abs(a-d)+abs(b-e)+abs(c-f))
