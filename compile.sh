#!/bin/bash

if [ $# -lt 1 ]; then
    echo "  "
    echo " ./compile.sh LFI-Aerodinamica.tex"
    echo " ./compile.sh LFI-Pohl.tex"
    echo " ./compile.sh LFI-Examen.tex"
    echo "  "
    echo " ./compile.sh FBIII-Problemas.tex"
    echo " ./compile.sh FBIII-Practica-6.tex"
    echo " ./compile.sh FBIII-Examen.tex"
    echo "  "
    exit -1
fi

export INPUT=$1

pdflatex ${INPUT}
bibtex
pdflatex ${INPUT}
