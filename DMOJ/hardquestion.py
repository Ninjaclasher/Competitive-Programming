g = float(input())
c = float(input())
t = float(input())

t0 = (-c + (c**2 + 2 * g * c * t)**0.5) / g
print(g * t0**2 / 2)
print(g * t0)
