;     Modulo 0
;   =============
;   Error test 10

push int32(32)
push int32(0)
mod
dump
pop
push int16(32)      ; float mod should return an exception
push float(0.000001)
mod
dump
pop
push int8(81)
push double(0.0)
mod
dump
exit
