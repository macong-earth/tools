#! /usr/bin/python
#filename = raw_input("Enter your input:")
#print "Received input is : ", str

import sys

if len(sys.argv) != 2:
    print "Usage: python lemmatizer.py filename"
    sys.exit(1)

f = open(sys.argv[1], 'r')
all_words = map(lambda l: l.split(" "), f.readlines())

from nltk.stem import WordNetLemmatizer
import re

lemmatizer = WordNetLemmatizer()

for line_words in all_words:
    for word in line_words:
        word = word.lower()
        word = re.sub('^[^a-z]+', '', word)
        word = re.sub('[^a-z]+$', '', word)
        origin_word = word
        origin_word = lemmatizer.lemmatize(word, pos='n')
        if origin_word == word:
            origin_word = lemmatizer.lemmatize(word, pos='v')
        print origin_word
