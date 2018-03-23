#ajfngsdv

.name "Bermudski"
.comment "Live is .."

f1: ld  %4, r2
    zjmp    %:run
run:	xor r0, r0, r0
lives:
		live %1
		zjmp %:lives
live:	live %-2
		fork %:l2
fork:	fork %:lives
l2:		sti	r1,%:lives,%0
		and	r1,%0,r1
