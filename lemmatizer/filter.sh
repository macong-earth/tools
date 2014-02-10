#! /bin/bash

python ./scripts/lemmatizer.py $(pwd)/$1 | tr '[:upper:]' '[:lower:]' | sort -u > uni
./bin/mygrep.exe wordlist.txt uni > newwords.txt 
#rm uni 
