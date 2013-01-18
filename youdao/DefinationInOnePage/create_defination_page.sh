#!bash

words=`cat $1`
for word in $words
do
  if [ ! -f cache/${word}.html ]
	then
		curl "http://dict.youdao.com/search?le=eng&q=${word}&keyfrom=dict.index" > cache/${word}.html
	fi
done

cd cache

../GeneratePage.exe $words > ../defination.html
