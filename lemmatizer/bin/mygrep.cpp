#include <set>
#include <map>
#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <algorithm> // for std::copy

int main(int argc, char * argv[])
{
	if (argc >= 3) {
		std::ifstream wordlistIs(argv[1]);
		std::istream_iterator<std::string> start(wordlistIs), end;
		std::set<std::string> words(start, end);

		std::ifstream dictionaryIs("dictionary/oxford.txt");
		std::map<std::string, std::string> dictionary;
		std::string line;
		size_t splitPos = 0;
		while(std::getline(dictionaryIs, line)) {
			if ((splitPos = line.find('\t')) != std::string::npos) {
				dictionary.insert(std::make_pair( line.substr(0, splitPos), line));
			}
		}

		std::ifstream articalIs(argv[2]);
		std::string word;
		while(articalIs) {
			articalIs >> word;
			if (words.find(word) != words.end()) {
				auto it = dictionary.find(word);
				if ( it != dictionary.end()) {
					std::cout << it->second << std::endl;
				} else {
					std::cout << word << std::endl;
				}
			}
			word.clear();
		}

		std::cout << std::endl;
	}
	return 0;

}

