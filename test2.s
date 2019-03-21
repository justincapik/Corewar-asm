.name "bualala"
.comment "I hope this works too"

ld %10, r2
st r1, 6
live:	live %-1
		zjmp %:live
