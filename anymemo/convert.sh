#! /bin/bash

for file in `ls html`
do
	_file=`basename $file`
	_file=${_file:0:3}
    echo "./AnymemoConvert html/$file > txt/$_file.txt"
    ./AnymemoConvert html/$file > txt/$_file.txt
done
