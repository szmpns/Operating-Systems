#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Użycie: $0 <zakres X> <zakres Y>"
    exit 1
fi

zakres_x=$1
zakres_y=$2

liczba_pytan=0
poprawne_odpowiedzi=0
niepoprawne_odpowiedzi=0

while true; do
    num1=$((1 + RANDOM % zakres_x))
    num2=$((1 + RANDOM % zakres_y))

    read -p "Ile to jest $num1 razy $num2? (Wpisz 0 lub mniej, aby zakończyć): " odpowiedz

    if [ $odpowiedz -le 0 ]; then
        break
    fi

    ((liczba_pytan++))

    if [ $odpowiedz -eq $((num1 * num2)) ]; then
        echo "Poprawna odpowiedź!"
        ((poprawne_odpowiedzi++))
    else
        echo "Niepoprawna odpowiedź. Prawidłowa odpowiedź to $((num1 * num2))."
        ((niepoprawne_odpowiedzi++))
    fi
done


echo -e "\nStatystyki quizu:"
echo "Liczba pytań: $liczba_pytan"
echo "Poprawne odpowiedzi: $poprawne_odpowiedzi"
echo "Niepoprawne odpowiedzi: $niepoprawne_odpowiedzi"