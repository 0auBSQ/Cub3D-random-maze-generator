;     Division 0
;   ==============
;   Error test 9

push int32(32)
push int32(0)
div
dump
pop
push float(32.0)      ; correct case
push float(0.000001)
div
dump
pop
push int8(81)
push double(0.0)
div
dump
exit
