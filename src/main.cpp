#include "../include/io.h"
#include <iostream>

void printValue(int value){
    std::cout<<value<< '\n';
}
int main()
{
    // int z { readNumber() };
    // int y { readNumber() };
    // writeAnswer(z,y);
    // std::cout << "kill yourself" << '\n';
    printValue(1);
    printValue(2);
    printValue(5);
    int x{ 1 };
    std::cout << x << ' ';

    x=x+2;
    std::cout << x << ' ';

    x=x+3;
    std::cout << x << ' ';

    return 0;
}