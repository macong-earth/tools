#!bash

getBaseFileName()
{
	filename=$(basename "$1")
	filename="${filename%.*}"
}

function createOneFile()
{
	if [ ! -f $1 ]
	then
		echo "$1 is not a file"
		exit
	fi

	words=`cat $1`

	for word in $words
	do
		if [ ! -f cache/${word}.html ]
		then
			curl "http://dict.youdao.com/search?le=eng&q=${word}&keyfrom=dict.index" > cache/${word}.html
		fi
	done

	cd cache

	
	getBaseFileName "../${1}"
	../bin/GeneratePage.exe $words > $2/${filename}.html
	cd ..
}

if [ "$1" == "" ]
then
	echo "Usage: create_defination_page wordlistfile"
	exit
fi

path=$1

if [ -f $path ] 
then
	createOneFile $path ..
elif [ -d $path ] 
then
	for fileitem in `ls $path`
	do
		echo $path/$fileitem
		createOneFile $path/$fileitem ../output
	done
else
	echo -e "Error: $path is not a file or folder."
	exit
fi


