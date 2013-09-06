#! /bin/bash

for file in `ls html`
do
    echo "./AnymemoConvert html/$file > txt/`basename $file`.txt"
    ./AnymemoConvert html/$file > txt/`basename $file`.txt
done
