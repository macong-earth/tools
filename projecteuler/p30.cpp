#include <iostream>
#include <cmath>

int main(void)
{
    const int digitLen = 5;
    const int min = 2;
    const int max = 1000000; // what's the max ?
    const int pows [] = {
        0,
        1,
        (int)std::pow((double)(2), digitLen),
        (int)std::pow((double)(3), digitLen),
        (int)std::pow((double)(4), digitLen),
        (int)std::pow((double)(5), digitLen),
        (int)std::pow((double)(6), digitLen),
        (int)std::pow((double)(7), digitLen),
        (int)std::pow((double)(8), digitLen),
        (int)std::pow((double)(9), digitLen)
    };

    std::cout << min << "," << max << std::endl;

    int num = 0;
    int sum = 0;
    for (int num = min; num < max; num++) {
        int sumOfExp = 0;
        int currentNum = num;
        while (currentNum > 0) {
            sumOfExp += pows[currentNum%10];
            currentNum /= 10;
        }
        if (num == sumOfExp) {
            std::cout << num << std::endl;
            sum += sumOfExp;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
