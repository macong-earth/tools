#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void mulBy2(std::vector<char> & num) {
    char carry_bit = 0;
    for (int i = 0; i < num.size(); i++) {
        char value = num[i] * 2 + carry_bit;
        num[i] = value % 10;
        carry_bit = value / 10;
    }
    if (carry_bit) {
        num.push_back(carry_bit);
    }
}

std::string toString(const std::vector<char> & num) {
    std::string s(num.data(), num.size());
    std::reverse(s.begin(), s.end());
    std::for_each(s.begin(), s.end(), [](char & ch) {
            ch += '0';
            });
    return s;
}

int digitSum (const std::vector<char> & num) {
    int sum = 0;
    std::for_each(num.begin(), num.end(), [&sum](const char & ch) {
            sum += ch;
            });
    return sum;
}

int main(void)
{
    std::vector<char> num;
    num.push_back((char)1);

    for (int i = 0; i < 1000; i++)
        mulBy2(num);

    std::cout << digitSum(num) << std::endl;

    return 0;
}
