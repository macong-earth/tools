#! /bin/bash

./scripts/lemmatizer.py $(pwd)/$1 | tr '[:upper:]' '[:lower:]' | sort -u > uni
fgrep -xvf words/word45 uni > without45
fgrep -xvf words/word3 without45 > without345
fgrep -xf words/word2 without345 > newwords2
fgrep -xf words/word1 without345 > newwords1
rm uni without45 without345
