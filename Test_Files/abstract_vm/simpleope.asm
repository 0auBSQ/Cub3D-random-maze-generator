; -------------
; simpleope.asm -
; -------------

push int8(42)
push int8(8)
add
dump
assert int8(50)
push int8(20)
sub
dump
assert int8(30)
push int16(3)
div
dump
assert int16(10)
push int32(3)
mod
dump
assert int32(1)
pop
dump
exit
