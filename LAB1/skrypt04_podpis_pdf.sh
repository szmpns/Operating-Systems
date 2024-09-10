#!/bin/bash

if [ "$#" -ne 4 ]; then
    echo "Sposób użycia: $0 <dokument.pdf> <podpis.png> <x> <y>"
    exit 1
fi

dokument_pdf="$1"
podpis_png="$2"
x="$3"
y="$4"

if [ ! -f "$dokument_pdf" ]; then
    echo "Plik PDF '$dokument_pdf' nie istnieje."
    exit 1
fi

if [ ! -f "$podpis_png" ]; then
    echo "Plik PNG '$podpis_png' nie istnieje."
    exit 1
fi

convert "$dokument_pdf" "$podpis_png" -geometry +$x+$y -composite "podpisany_dokument.pdf"

if [ $? -eq 0 ]; then
    echo "Podpisano dokument i zapisano jako 'podpisany_dokument.pdf'."
else
    echo "Wystąpił błąd podczas podpisywania dokumentu."
fi