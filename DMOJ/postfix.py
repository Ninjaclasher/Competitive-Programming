cur = input().split()
buf = []

for x in cur:
    try:
        x = float(x)
    except ValueError:
        b = buf.pop()
        a = buf.pop()
        if x == '+':
            c = a + b
        elif x == '-':
            c = a - b
        elif x == '/':
            c = a / b
        elif x == '*':
            c = a * b
        elif x == '%':
            c = a % b
        elif x == '^':
            c = a ** b
        buf.append(c)
    else:
        buf.append(x)

assert len(buf) == 1

print(buf[0])
