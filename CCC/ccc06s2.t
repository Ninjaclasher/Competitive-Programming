var plain : string
var cipher : string
var input : string
get plain : *
get cipher : *
get input : *

var code : array 1 .. 26 of char := init ('.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.')

for a : 1 .. length (plain)
    if cipher (a) not= ' ' then
        code (ord (cipher (a)) - 64) := plain (a)
    end if
end for

for x : 1 .. length (input)
    put code (ord (input (x)) - 64) ..
end for
