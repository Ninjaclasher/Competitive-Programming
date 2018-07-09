var s : int
var a : int
get s
get a
var k : int := 1
loop
s := s - a
k += 1
exit when s < 0
a := a - s
k+= 1
exit when a < 0
end loop
put k
