;     Pop Empty
;   =============
;   Error test 2

push int8(15)
dump
pop
push int16(-27)
pop
pop
dump
push int32(-17)
push float(1.25)
mul
dump
pop
pop
pop
push int8(45)
print
exit
