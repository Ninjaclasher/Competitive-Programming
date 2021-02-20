n = int(input())
assert 1 <= n <= 100
bst_bid = -1e10
bst_name = ''
for i in range(n):
    name = input()
    bid = int(input())
    assert 1 <= bid <= 2000
    if bid > bst_bid:
        bst_bid = bid
        bst_name = name

print(bst_name)
