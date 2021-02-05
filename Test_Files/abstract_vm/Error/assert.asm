;     Assert
;   =============
;   Error test 12

assert int32(56)
push int32(56)
assert int32(0)
assert int32(56)  ; valid
assert int16(56)
assert float(56.0)
assert double(56.0)
assert int8(56)
dump
exit
