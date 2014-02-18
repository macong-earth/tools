#! /bin/bash

if [ "$1" == "" ]
then
    echo "Usage: filter input"
    exit
fi

rm newwords result.html

cat "$(pwd)/$1" | while read line; do
for word in $line; do
    echo $word
done
done | tr '[:upper:]' '[:lower:]' | sort -u > splitewords

python ./scripts/lemmatizer.py splitewords > uni

for (( i = 6 ; i <= 20 ; i++ ))
do
    echo "#[$i]" >> newwords
    ./bin/mygrep.exe wordlists/$i.txt uni >> newwords
done

cat ./scripts/header.template > result.html
./bin/lookup.exe newwords ./dictionary/oxford.txt >> result.html
cat ./scripts/tail.template >> result.html

rm uni splitewords
