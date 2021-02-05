; -------------
; amplitude.asm -
; -------------

push int8(42)
push int32(9999958)
add
assert int32(10000000)
push int8(70)
push int32(10000000)
add
assert int32(10000070)
dump
push float(1000.0)
div
assert float(10000.07)
dump
push float(45454545.9)
assert float(45454545.9)
dump
exit
