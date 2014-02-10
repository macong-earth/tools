#include <set>
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

		std::ifstream articalIs(argv[2]);
		std::string word;
		while(articalIs) {
			articalIs >> word;
			if (words.find(word) != words.end()) {
				std::cout << word << "\n";
			}
			word = "";
		}

		std::cout << std::endl;
	}
	return 0;

}

