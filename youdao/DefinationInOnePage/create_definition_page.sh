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
		anywait
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

echo "Input the file or folder name"
read path

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
	echo -e "\n###Error: $path is not a file or folder.\nPress Enter to exit."
	read
fi

