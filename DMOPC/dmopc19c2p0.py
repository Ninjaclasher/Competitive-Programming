n, a, b = map(int, input().split())

print(len([x for x in map(int, input().split()) if a <= x <= b]))
