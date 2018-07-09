import sys
input = sys.stdin.readline().split(' ')
h, m, s = [int(x) for x in input]
m += s/60
s %= 60
h += m/60
m %= 60
h = 12 - h%12
if s != 0 or m != 0:
    h -= 1
else:
    h %= 12
to_print = ""
if h < 10:
    to_print += "0"
to_print += str(h) + ":"
m = (60-m)%60
if s != 0:
    m -= 1
if m < 10:
    to_print += "0"
to_print += str(m) + ":"
s = (60-s)%60
if s < 10:
    to_print += "0"
to_print += str(s)

print to_print
