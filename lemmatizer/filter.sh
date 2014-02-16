#! /bin/bash

if [ "$1" == "" ]
then
echo "Usage: filter input"
exit
fi

python ./scripts/lemmatizer.py $(pwd)/$1 | tr '[:upper:]' '[:lower:]' | sort -u > uni

echo "" > result.txt
for (( i = 6 ; i <= 20 ; i++ ))
do
echo "< $i >" >> result.txt
./bin/mygrep.exe wordlists/$i.txt uni >> result.txt 
done
rm uni 
