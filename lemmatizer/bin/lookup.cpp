#include <set>
#include <map>
#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <algorithm> // for std::copy

int main(int argc, const char *argv[])
{
    if (argc >= 3) {
        std::ifstream dictionaryIs(argv[2]);
        std::map<std::string, std::string> dictionary;
        std::string line;
        size_t splitPos = 0;
        while(std::getline(dictionaryIs, line)) {
            if ((splitPos = line.find('\t')) != std::string::npos) {
                dictionary.insert(std::make_pair( line.substr(0, splitPos), line));
            }
        }

        std::ifstream wordlistIs(argv[1]);
        std::string word;
        while (wordlistIs >> word) {
            if ('#' != word[0]) {
                auto it = dictionary.find(word);
                if ( it != dictionary.end()) {
                    std::cout << "<a onclick=\"pronounce('" << it->first << "')\">" << it->second << "</a><br>" << std::endl;
                } else {
                    std::cout << word << "<br>" << std::endl;
                }
            } else {
                std::cout << word << "<br>" << std::endl;
            }
        }

        return 0;
    }
    return -1;
}
