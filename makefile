outfile:add.o delete.o show.o modify.o save.o sort.o main.o
	cc add.c delete.c show.c modify.c save.c sort.c main.c -o student

add.o:add.c
	cc -c add.c

delete.o:delete.c
	cc -c delete.c

show.o:show.c
	cc -c show.c

modify.o:modify.c
	cc -c modify.c

save.o:save.c
	cc -c save.c

sort.o:sort.c
	cc -c sort.c

main.o:main.c
	cc -c main.c
