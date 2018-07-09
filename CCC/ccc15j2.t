var s : string
get s : *
var a : int := 0
var j : boolean := false
for x : 1 .. length (s)
    if s (x) = ':' then
        j := true
        if s (x + 2) = '(' then
            a -= 1
        elsif s (x + 2) = ')' then
            a += 1
        end if
    end if
end for
if j then
    if a > 0 then
        put "happy"
    elsif a < 0 then
        put "sad"
    elsif a = 0 then
        put "unsure"
    end if
else
    put "none"
end if
