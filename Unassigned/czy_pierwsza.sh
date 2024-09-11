#!/bin/bash

while true; do
    read -p "Podaj liczbe, aby sprawdzic, czy jest pierwsza: " liczba

    jest_pierwsza=true

    for ((i = 2; i < liczba; i++)); do
        if [ $((liczba % i)) -eq 0 ]; then
            jest_pierwsza=false
            break
        fi
    done

    if $jest_pierwsza; then
        echo "Jest pierwsza"
    else
        echo "Nie jest pierwsza"
    fi
done