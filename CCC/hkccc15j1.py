n = int(input())
a = input().split()
b = input().split()
c = [0, 0]
for i in range(n):
    if a[i] == b[i]:
        continue
    if a[i] == "rock":
        c[b[i] == "paper"] += 1
    elif a[i] == "paper":
        c[b[i] == "scissors"] += 1
    elif a[i] == "scissors":
        c[b[i] == "rock"] += 1

print(*c)     
