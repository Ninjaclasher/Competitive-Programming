var i : array 1 .. 16 of int
var s : boolean := true
for x : 1 .. 16
    get i (x)
end for
var o : int := i (1) + i (2) + i (3) + i (4)

for x : 5 .. 13 by 4
    if i (x) + i (x + 1) + i (x + 2) + i (x + 3) not= o then
        s := false
    end if
    exit when not s
end for
for x : 1 .. 4
    exit when not s
    if i (x) + i (x + 4) + i (x + 8) + i (x + 12) not= o then
        s := false
    end if
end for

if s then
    put "magic"
else
    put "not magic"
end if
