a = int(input())
b = int(input())
k = a * b
ot = ['00', '25', '50', '75']
print('{}.{}'.format(k // 4, ot[k % 4]))
