main: build/files.o build/process.o build/sorter.o build/main.o
	gcc build/files.o build/process.o build/main.o build/sorter.o -o exe

build/files.o: source/files.c source/files.h 
	gcc -g -c  -Wall -Wextra -Werror -std=c99 -pedantic ./source/files.c -o build/files.o

build/process.o: source/process.c source/process.h
	gcc -g -c  -Wall -Wextra -Werror -std=c99 -pedantic ./source/process.c -o build/process.o

build/sorter.o: source/sorter.c source/sorter.h
	gcc -g -c  -Wall -Wextra -Werror -std=c99 -pedantic ./source/sorter.c -o build/sorter.o

build/main.o: source/main.c
	gcc -g -c  -Wall -Wextra -Werror -std=c99 -pedantic  ./source/main.c -o build/main.o

clean:
	rm build/*.o
	rm exe
	rm tmp_in/*
	rm tmp_out/*

