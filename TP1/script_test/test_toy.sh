#!/bin/bash
for i in {0..9};
do 
	echo "testando o ${i}-esimo teste toy";
  ../solucao/exe < ../toys/entrada/toy_${i}_entrada > ../minhasaida/saida_${i}
  diff ../toys/saida/toy_${i}_saida ../minhasaida/saida_${i}
done
