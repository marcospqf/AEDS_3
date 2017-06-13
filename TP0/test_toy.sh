#!/bin/bash
for i in {0..9};
do 
	echo "testando o ${i}-esimo teste toy";
  ./TP0/exe < ./entrada/toy_${i}_entrada > ./minhasaida/saida_${i}
  diff ./saida/toy_${i}_saida ./minhasaida/saida_${i}
done
