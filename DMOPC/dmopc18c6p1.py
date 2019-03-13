n=int(input())
a=input()
ALL="ACGTU"
for x in a:
    if x not in ALL:
        print("neither")
        break
else:
    TT = "T" in a
    UU = "U" in a
    if TT and UU:
        print("neither")
    elif TT:
        print("DNA")
    elif UU:
        print("RNA")
    else:
        print("both")
