a = [
    ('0', 'O'),
    ('1', 'l'),
    ('3', 'E'),
    ('4', 'A'),
    ('5', 'S'),
    ('6', 'G'),
    ('8', 'B'),
    ('9', 'g'),
]
s = input()
for i in a:
    s = s.replace(*i)
print(s)
