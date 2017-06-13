#!/bin/bash
for i in {0..11};
do 
	echo "testando o ${i}-esimo meu_teste"
  start_time="$(date -u +%s.%N)"
  ./TP0/exe < ./minha_entrada/in${i}
  end_time="$(date -u +%s.%N)"
  elapsed="$(bc <<<"$end_time-$start_time")"
  echo "$elapsed segundos para processar"
done
