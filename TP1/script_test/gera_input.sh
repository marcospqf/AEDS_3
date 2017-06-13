#!/bin/bash
for i in {1..50};
do 
	echo "testando o ${i}-esimo meu_teste"
	g++ test.cpp -o test
	./test >> ../teste/in_${i}
	echo "XABLAU"
	sleep 5
done

