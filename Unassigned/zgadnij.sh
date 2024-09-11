#!/bin/bash

liczba=$((1 + RANDOM % 100))
proby=0

while true;do
	read -p "zgadnij liczbe od 1 do 100: " strzal
	
	((proby++))

	if [ $strzal -eq $liczba ];then
		echo "Gratulacje, to była liczba $liczba"
		break
	fi

	if [ $strzal -gt $liczba ]; then
		echo "To za duzo"
	else
		echo "To za mało"
	fi

done

echo "Udalo Ci sie zgadnac po $proby probach"