#! /bin/bash

./bin/simple_lookup.exe  unknown.txt ./dictionary/oxford.txt >> anymemo.txt 
sort -u anymemo.txt > temp
mv temp anymemo.txt
