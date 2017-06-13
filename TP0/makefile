main: stack.o solver.o main.o 
	gcc stack.o main.o solver.o -o  exe
stack.o: stack.c stack.h 
	gcc -g -c  -Wall -Wextra -Werror -std=c99 -pedantic  stack.c
solver.o: solver.c solver.h
	gcc -g -c  -Wall -Wextra -Werror -std=c99 -pedantic solver.c
main.o: main.c
	gcc -g -c  -Wall -Wextra -Werror -std=c99 -pedantic  main.c
clean:
	rm *.o
	rm exe

