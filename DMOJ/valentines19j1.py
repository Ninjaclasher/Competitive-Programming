import sys
import bisect
vv = [-10**9, 1000, 1200, 1500, 1800, 2200, 3000, 4000]
nn = ["Newbie", "Amateur", "Expert", "Candidate Master", "Master", "Grandmaster", "Target", "Rainbow Master"]
for v in map(int,sys.stdin.read().split()[1:]):
    print(nn[bisect.bisect(vv, v)-1])
