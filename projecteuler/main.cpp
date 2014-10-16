#include "divisors.h"

using namespace Euler;

int main(void)
{

    auto primes = PrimeFactorization(100);
    std::cout << primes << std::endl;

    return 0;
}

