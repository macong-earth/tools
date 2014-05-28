//The Fibonacci sequence is defined by the recurrence relation:

//Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
//Hence the first 12 terms will be:

//F1 = 1
//F2 = 1
//F3 = 2
//F4 = 3
//F5 = 5
//F6 = 8
//F7 = 13
//F8 = 21
//F9 = 34
//F10 = 55
//F11 = 89
//F12 = 144
//The 12th term, F12, is the first term to contain three digits.

//What is the first term in the Fibonacci sequence to contain 1000 digits?

#include "big_number.h"
#include <iostream>

int main(void)
{
    int index = 2;
    const size_t len = 1000;

    Euler::BigNum n1("1");
    Euler::BigNum n2("1");

    while (n1.size() < len && n2.size() < len) {
        ++index % 2 == 0 ? n2 + n1 : n1 + n2;
        //std::cout << index << " " << (index % 2 == 0 ? n2 : n1).toString() << std::endl;
    }

    std::cout << n1.size() << " " << n1.toString() << std::endl;
    std::cout << n2.size() << " " << n2.toString() << std::endl;
    std::cout << index << std::endl;


    return 0;
}


//Fibonacci terms converge to (n)*Phi=(n+1), where Phi is the
 //Golden Ratio (1+sqrt5)/2.
//I reasoned that there is an nth term that is smaller than 10^999
 //with the corresponding nth+1 term bigger than 10^999.
//So, using the binary splitting method for searching, I used
 //the MS calculator and found Phi^4780<10^999 and Phi^4781>10^999.
//Since the two initial terms of the series have the same value
 //by definition, you have to add one to the exponents found.
//No code necessary.
//Rudy.
