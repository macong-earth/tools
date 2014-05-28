#include <iostream>


int d(int num) {
    int sum = 0;
    for (int i = num - 1; i > 0 ; i--) {
        sum += num % i == 0 ? i : 0;
    }
    return sum;
}

int main(int argc, char const* argv[])
{
    int sums [10001];
    int sum = 0;

    for (int i = 0; i <= 10000; i++) {
        sums[i] = d(i);
    }

    for (int i = 0; i <= 10000; i++) {
        if (sums[i] <= 10000 && sums[sums[i]] <= 10000 &&
                i != sums[i] && i == sums[sums[i]]) {
            std::cout << i << "," << sums[i] << std::endl;
            sum += i;
        }
    }

    std::cout << sum << std::endl;


    return 0;
}
