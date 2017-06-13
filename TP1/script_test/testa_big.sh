#!/bin/bash
for i in {1..50};
do 
	echo "testando o ${i}-esimo meu_teste"
	start_time="$(date -u +%s)"
	../solucao/exe < ../teste/in_${i}
	./corrige < ../teste/in_${i} >>in
	end_time="$(date -u +%s)"
	elapsed="$(bc <<<"$end_time-$start_time")"
	echo "$elapsed" >> in
done

