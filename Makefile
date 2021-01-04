all: babyQuery babiesQuery

babiesQuery: babiesQuery.o removeCommas.o
	gcc -ansi -Wall -o babiesQuery babiesQuery.o removeCommas.o

babiesQuery.o: babiesQuery.c
	gcc -ansi -Wall -c babiesQuery.c

babyQuery: babyQuery.o removeCommas.o
	gcc -ansi -Wall -o babyQuery babyQuery.o removeCommas.o

babyQuery.o: babyQuery.c
	gcc -ansi -Wall -c babyQuery.c

removeCommas.o: removeCommas.c
	gcc -ansi -Wall -c removeCommas.c

clean:
	rm *.o babiesQuery babyQuery
