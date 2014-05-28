//A permutation is an ordered arrangement of objects. For example, 3124 is one possible
//permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed
//numerically or alphabetically, we call it lexicographic order. The lexicographic
//permutations of 0, 1 and 2 are:

//012   021   102   120   201   210

//What is the millionth lexicographic permutation of the digits
//0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
//
// 2783915460

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include "print.h"

long long getFactorial(int value) {
    long long factorial = 1;
    for (int i = 1; i <= value; i++) {
        factorial *= i;
        if (factorial < 0) return 0;
    }
    return factorial;
}

int main(int argc, char const* argv[])
{

    std::string millionthPermutation;
    std::string digits = "0123456789";

    int factorials[10] = {0};
    for (int i = 1; i < sizeof(factorials)/sizeof(factorials[0]); i++) {
        factorials[i] = getFactorial(i);
    }

    int number = 1000000;
    for (int i = 0; i < 10; i++) {
        size_t pos = number/factorials[digits.size()-1];
        number %= factorials[digits.size()-1];
        millionthPermutation += digits[pos];
        digits.erase(pos, 1);
        if (number == 0) {
            break;
        }
    }

    millionthPermutation += digits;

    std::prev_permutation(millionthPermutation.begin(), millionthPermutation.end());
    std::cout << millionthPermutation << std::endl;

    return 0;
}
