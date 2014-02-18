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
        char * sourceFileName = NULL;
        char * filterFileName = NULL;
        bool isInvert         = false;

        if (strcmp("-v", argv[1]) == 0) {
            sourceFileName = argv[2];
            filterFileName = argv[3];
            isInvert = true;
        } else {
            sourceFileName = argv[1];
            filterFileName = argv[2];
        }

        std::ifstream wordlistIs(sourceFileName);
        std::istream_iterator<std::string> start(wordlistIs), end;
        std::set<std::string> words(start, end);

        std::ifstream articalIs(filterFileName);
        std::string word;
        while(articalIs >> word) {
            if ((words.find(word) != words.end()) != isInvert) {
                    std::cout << word << std::endl;
            }
        }

        std::cout << std::endl;
        return 0;
    }
    return -1;

}

