// p 23
//A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
//For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that
//28 is a perfect number.

//A number n is called deficient if the sum of its proper divisors is less than n and it is called
//abundant if this sum exceeds n.

//As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written
//as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers
//greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot
//be reduced any further by analysis even though it is known that the greatest number that cannot be
//expressed as the sum of two abundant numbers is less than this limit.

//Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
//
//4179871

#include "divisors.h"
#include <iostream>
#include <vector>
#include <numeric>

bool isAbundantNum(unsigned short value) {
        auto v = Euler::GetDivisorsSorted(value);
        unsigned int sum = std::accumulate(v.begin(), v.end(), 0);

        return (sum > value);
}

template<typename T>
bool isSumOfAbundant(T value, const std::vector<bool> & abundants) {
    for (T i = 12; i <= value/2 ; i++ ) {
        if (abundants[i] && abundants[value-i]) {
            return true;
        }
    }
    return false;
}

int main(void)
{
    const unsigned short MaxNum = 28123;

    std::vector<bool> isAbundantNums(MaxNum, false);

    unsigned sum = 0;
    for (unsigned short i = 1; i < MaxNum; i++ ) {
        isAbundantNums[i] = isAbundantNum(i);
    }

    for (unsigned short i = 1; i < MaxNum; i++ ) {
        sum += isSumOfAbundant(i, isAbundantNums) ? 0 : i;
    }

    std::cout << sum << std::endl;
    return 0;
}
