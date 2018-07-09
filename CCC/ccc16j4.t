var t, hm, mh : string := ""
var h, m : int
get t : *
h := strint (t (1 .. 2))
m := strint (t (4 .. 5))

for x : 1 .. 120
    if h > 6 and h < 10 or h > 14 and h < 19 then
        m += 2
    else
        m += 1
    end if
    if m = 60 then
        h += 1
        m := 0
    end if
    if h = 24 then
        h := 0
    end if
end for
if length (intstr (m)) = 1 then
    mh := "0"
end if
if length (intstr (h)) = 1 then
    hm := "0"
end if
put hm, h, ":", mh, m
