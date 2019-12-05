n = int(input())
for i in range(n):
    arr = list(map(int, input().split()))
    arithmetic = all(arr[i] + arr[i+2] == arr[i+1] * 2 for i in range(8))
    geometric = all(arr[i] * arr[i+2] == arr[i+1]**2 for i in range(8))
    if arithmetic and geometric:
        print('both')
    elif arithmetic:
        print('arithmetic')
    elif geometric:
        print('geometric')
    else:
        print('neither')
