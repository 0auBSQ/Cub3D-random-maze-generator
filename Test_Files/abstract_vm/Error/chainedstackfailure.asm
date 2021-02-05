;     Chained stack failure
;   =========================
;   Error test 18

push float(99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0)
push int8(6)
dump
mul
dump
pop
ush int32(32)
push int32(0)
div
dump
pop
print
print
pop
push int8(80)
add
push int8(80)
add
push int8(80)
add
push int8(80)
div
push int8(80)
mod
mod
mod
push int32(30)
push int16(20)
push int8(50)
print
add
assert int16(70)
print
add
assert int32(100)
print
dump
push int8(5
dump
pop
push int7(12)
dump
pop
push int8 12)
dump
pop
push int8((12)
dump
pop
push int8(12))
dump
pop
push int8((12))
dump
pop
push int8(12.45)
dump
pop
pop int8(12)
dump
push
