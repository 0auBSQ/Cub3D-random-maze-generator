;     Division 0+
;   ==============
;   Error test 15

push float(32.0)      ; correct case
push float(0.0000000000000000000000000000000000001)
div
dump
pop
push float(32.0)      ; div /0
push float(0.00000000000000000000000000000000000001)
div
dump
pop
exit
