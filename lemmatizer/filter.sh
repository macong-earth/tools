#! /bin/bash

./scripts/lemmatizer.py $(pwd)/$1 | tr '[:upper:]' '[:lower:]' | sort -u > uni
fgrep -xvf words/word45 uni > result
fgrep -xf words/word3 result > newwords3
fgrep -xf words/word2 result > newwords2
fgrep -xf words/word1 result > newwords1
rm uni
rm result
