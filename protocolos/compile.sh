#!/bin/bash

if [ $# -lt 1 ]; then
    echo "  "
    echo " ./compile.sh TocarLaCiencia001.tex"
    echo "  "
    exit -1
fi

export INPUT=$1

pdflatex ${INPUT}
bibtex
pdflatex ${INPUT}
