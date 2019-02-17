print(sum(240 <= r <= 255 and 0 <= g <= 200 and 95 <= b <= 220 for r, g, b in (map(int,input().split()) for x in range(int(input())))))
