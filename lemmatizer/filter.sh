#! /bin/bash

if [ "$1" == "" ]
then
echo "Usage: filter input"
exit
fi

python ./scripts/lemmatizer.py $(pwd)/$1 | tr '[:upper:]' '[:lower:]' | sort -u > uni

cat ./scripts/header.template > result.html

for (( i = 6 ; i <= 20 ; i++ ))
do
echo "[ $i ]<br>" >> result.html
./bin/mygrep.exe wordlists/$i.txt uni >> result.html
done

cat ./scripts/tail.template >> result.html
rm uni 
