var s : int
get s
var d : boolean := false
if s = 1 then
    put 2
elsif s = 2 then
    put 2
else
    for a : s .. s + 100000000
        for b : 2 .. ceil (sqrt (a))
            exit when a mod b = 0
            if b = ceil (sqrt (a)) then
                put a
                d := true
            end if
            exit when d
        end for
        exit when d
    end for
end if
