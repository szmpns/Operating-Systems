#!/bin/bash

suma=0

read -p "Podaj liczbe: " liczba

while [ $liczba -gt 0 ];do
	
	suma=$((suma + liczba % 10))
	liczba=$((liczba/10))

done

echo "Suma: " $suma