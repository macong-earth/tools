#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


int main(void)
{
    std::ifstream ifile("p67.txt");
    std::string line;
    int num;
    std::vector<std::vector<int>> triArr;

    while(getline(ifile, line)) {
        std::stringstream innerSS(line);
        triArr.push_back(std::vector<int>());

        while (innerSS >> num) {
            triArr.back().push_back(num);
        }
    }

    while (triArr.size() > 1) {
        auto & lastLine = triArr[triArr.size()-1];
        auto & lastButOneLine = triArr[triArr.size()-2];

        for (int i = 0; i < lastButOneLine.size() ; i++) {
            lastButOneLine[i] = std::max(lastButOneLine[i] + lastLine[i],
                    lastButOneLine[i] + lastLine[i+1]);
        }
        triArr.pop_back();
    }

    std::cout << triArr[0][0] << std::endl;
    return 0;
}

