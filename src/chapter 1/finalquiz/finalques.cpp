#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";

    int num{ }, num1 { };
    std::cin >> num;

    std::cout << "Enter another integer: ";

    std::cin >> num1;

    std::cout << num << " + " << num1 << " is " << num + num1 << "\n";

    std::cout << num << " - " << num1 << " is " << num - num1 << "\n";

    return 0;
}