#include <iostream>

int main(void)
{
    const int Depth = (1001 + 1) / 2;
    int sum = 0;
    int numAtCorner = 1;

    sum += numAtCorner;

    for (int d = 1; d < Depth; d++) {
        for (int i = 1; i <= 4; i++) {
            numAtCorner += 2 * d;
            sum += numAtCorner;
        }

    }

    std::cout << sum << std::endl;


    return 0;
}
