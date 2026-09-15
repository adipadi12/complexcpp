#include <iostream>
#include <bits/stdc++.h>
#include <bitset>
#include <format> // C++ 20
#include <print> // C++ 23
using namespace std;

int main()
{
    int x {013}; // 0 before to denote number is an octal number
    int y {0xF};

    int bin{};    // assume 16-bit ints
    bin = 0x0001; // assign binary 0000 0000 0000 0001 to the variable

    // post C++ 14 we got binary literals
    int bin1{};        // assume 16-bit ints
    bin1 = 0b1;        // assign binary 0000 0000 0000 0001 to the variable

    int binlong { 0b1011'0010 };  // assign binary 1011 0010 to the variable
    long value { 2'132'673'462 }; // much easier to read than 2132673462

    cout << "The value of x is: " << x << endl; // Output: The value of x is: 10
    cout << y << '\n';

    /*CALLING std::hex/oct/dec changes the value too for later calls*/
    std::cout << x << '\n'; // decimal (by default)
    std::cout << std::hex << x << '\n'; // hexadecimal
    std::cout << x << '\n'; // now hexadecimal
    std::cout << std::oct << x << '\n'; // octal
    std::cout << x << '\n'; // now octal
    std::cout << std::dec << x << '\n'; // return to decimal
    std::cout << x << '\n'; // decimal

    // std::bitset<8> means we want to store 8 bits
	std::bitset<8> bin3{ 0b1100'0101 }; // binary literal for binary 1100 0101
	std::bitset<8> bin4{ 0xC5 }; // hexadecimal literal for binary 1100 0101

	std::cout << bin3 << '\n' << bin4 << '\n';
	std::cout << std::bitset<4>{ 0b1010 } << '\n'; // create a temporary std::bitset and print it

    std::cout << std::format("{:b}\n", 0b1010);  // C++20, {:b} formats the argument as binary digits
    std::cout << std::format("{:#b}\n", 0b1010); // C++20, {:#b} formats the argument as 0b-prefixed binary digits

    std::println("{:b} {:#b}", 0b1010, 0b1010);  // C++23, format/print two arguments (same as above) and a newline
    return 0;
}