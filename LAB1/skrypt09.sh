#!/bin/bash

echo "Podaj liczbe n elementtow ciagu Fibonacciego:"

read liczba

a=1
b=1

licznik=0

echo ""

while [ $licznik -lt $liczba ]; do
        echo "$a"
        nastepny=$((a+b))
        a=$b
        b=$nastepny
        licznik=$((licznik + 1))
done
