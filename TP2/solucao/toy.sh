#!/bin/bash
for i in {0..9};
do 
	echo "testando o ${i}-esimo teste toy";
	./exe < ../toys/toy_${i}_input 
   #diff ../toys/indices/toy_${i}/index ../toys/indices/toy_${i}/1
done

