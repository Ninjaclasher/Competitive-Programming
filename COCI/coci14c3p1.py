k = [
    "1QAZ",
    "2WSX",
    "3EDC",
    "4RFV5TGB",
    "6YHN7UJM",
    "8IK,",
    "9OL.",
    "0P;/-=[]'",
]
a = input()
cnt = [0] * 10
for x in a:
    for y in range(8):
        if x in k[y]:
            cnt[y] += 1
            break
for i in range(8):
    print(cnt[i])
        
