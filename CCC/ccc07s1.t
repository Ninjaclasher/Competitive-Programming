var y, m, d, n : int
get n
for x : 1 .. n
    get y, m ,d
    if y > 1989 then
        put "No"
    elsif y = 1989 then
        if m > 2 then
            put "No"
        elsif m = 2 then
            if d > 27 then
                put "No"
            else
                put "Yes"
            end if
        else
            put "Yes"
        end if
    else
        put "Yes"
    end if
end for
