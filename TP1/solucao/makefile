main: vector.o dinic.o solver.o main.o 
	gcc vector.o dinic.o solver.o main.o -o exe
vector.o: vector.c vector.h 
	gcc -g -c  -Wall -Wextra -Werror -std=c99 -pedantic vector.c
dinic.o: dinic.c dinic.h
	gcc -g -c  -Wall -Wextra -Werror -std=c99 -pedantic dinic.c
solver.o: solver.c solver.h
	gcc -g -c  -Wall -Wextra -Werror -std=c99 -pedantic solver.c
main.o: main.c
	gcc -g -c  -Wall -Wextra -Werror -std=c99 -pedantic  main.c
clean:
	rm *.o
	rm exe


