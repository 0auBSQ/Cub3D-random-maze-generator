;     Overflow 2
;   ==============
;   Error test 8

push int16(15835)
push int8(7)
dump
mul
dump
pop
push int8(114)      ; this one shouldn't overflow
push int16(-5832)
dump
add
dump
exit
