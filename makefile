
ll_tst: llist.o ll_tst.c
	gcc ll_tst.c llist.o -o ll_tst

rev_tst: llist.o rev_tst.c
	gcc rev_tst.c llist.o -o rev_tst

llist.o: list.h llist.c
	gcc -c llist.c

msort: llist.o msort.c
	gcc msort.c llist.o -o msort

qsort: llist.o qsort.c
	gcc qsort.c llist.o -o qsort
