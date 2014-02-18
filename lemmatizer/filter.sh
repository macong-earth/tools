#! /bin/bash

if [ "$1" == "" ]
then
    echo "Usage: filter input"
    exit
fi

rm result.html

cat "$(pwd)/$1" | while read line; do
for word in $line; do
    echo $word
done
done | tr '[:upper:]' '[:lower:]' | sort -u > splitewords

python ./scripts/lemmatizer.py splitewords | sort -u > uni

./bin/mygrep.exe -v wordlists/filter.txt uni > filtered

for (( i = 6 ; i <= 20 ; i++ ))
do
    echo "#[$i]"
    ./bin/mygrep.exe wordlists/$i.txt filtered
done > newwords

cat ./scripts/header.template > result.html
./bin/lookup.exe newwords ./dictionary/oxford.txt >> result.html
cat ./scripts/tail.template >> result.html

rm splitewords uni filtered newwords 
