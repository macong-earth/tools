#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

int getScore(const std::string & name) {
    int score = 0;
    std::for_each(name.begin(), name.end(), [&score](const char& ch) { score += ch - 'A' + 1;});
    return score;
}

int main(void)
{
    std::ifstream in("p22.txt");
    std::istream_iterator<std::string> start(in), tail;
    std::vector<std::string> names(start, tail);

    std::sort(names.begin(), names.end());

    long long sum = 0;
    for (int i = 0; i < names.size(); i++) {
        sum += (i+1) * getScore(names[i]);
    }

    std::cout << sum << std::endl;
    return 0;
}
