;     Overflow 1
;   ==============
;   Error test 7

push int8(15835)
push int8(-313)
dump
add
dump
pop
push int8(-214)
push int8(91)
dump
sub
dump
print
exit
