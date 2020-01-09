a = input()
b = input()

c = sum(a[i] != b[i] for i in range(len(a)))

print("LARRY IS {}!".format("DEAD" if c != 1 else "SAVED"))
