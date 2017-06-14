#!/bin/bash
for i in {0..9};
do 
	echo "testando o ${i}-esimo teste toy";
	./exe < toy_${i}_input 
   diff ./indices/toy_${i}/index ./indices/toy_${i}/1
done

