#!/bin/bash

function generuj_ruch_komputera() {
    ruchy=("kamień" "papier" "nożyce")
    wylosowany_indeks=$((RANDOM % 3))
    echo "${ruchy[$wylosowany_indeks]}"
}

function ocen_wynik() {
    gracz=$1
    komputer=$2

    if [ "$gracz" == "$komputer" ]; then
        echo "Remis!"
    elif ([ "$gracz" == "kamień" ] && [ "$komputer" == "nożyce" ]) || \
         ([ "$gracz" == "papier" ] && [ "$komputer" == "kamień" ]) || \
         ([ "$gracz" == "nożyce" ] && [ "$komputer" == "papier" ]); then
        echo "Gracz wygrywa!"
    else
        echo "Komputer wygrywa!"
    fi
}

echo "Wybierz ruch: kamień, papier, nożyce"
read -p "Twój ruch: " ruch_gracza

case $ruch_gracza in
    "kamień" | "papier" | "nożyce")
        ;;
    *)
        echo "Błędny wybór. Wybierz kamień, papier lub nożyce."
        exit 1
        ;;
esac

ruch_komputera=$(generuj_ruch_komputera)

echo "Komputer wybrał: $ruch_komputera"

ocen_wynik "$ruch_gracza" "$ruch_komputera"