#! /bin/bash


rm result.html

#cat "$(pwd)/$1" | while read line; do
cat input.txt | while read line; do
for word in $line; do
    echo $word
done
done | tr '[:upper:]' '[:lower:]' | sort -u > splitewords

python ./scripts/lemmatizer.py splitewords | sort -u > uni

./bin/mygrep.exe -v wordlists/filter.txt uni > filtered
cat filtered >> backup

for (( i = 1 ; i <= 21 ; i++ ))
do
    echo "#[$i]"
    ./bin/mygrep.exe wordlists/$i.txt filtered
done > newwords.txt

cat ./scripts/header.template > result.html
./bin/lookup.exe newwords.txt ./dictionary/oxford.txt >> result.html
cat ./scripts/tail.template >> result.html

rm splitewords uni filtered 
