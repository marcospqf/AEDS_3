#!/bin/bash
for i in {1..50};
do 
	echo "testando o ${i}-esimo meu_teste"
	g++ testbig.cpp -o exe
	./exe >> ../teste_2/in_${i}
	echo "XABLAU"
	sleep 5
done

