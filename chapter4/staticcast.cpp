#include <iostream>

int main()
{
    std::cout << "Enter a single character: ";
    char ch {};
    std::cin >> ch;
    int num { static_cast<int>(ch) };
    std::cout << "You entered '" << ch << "' which has ASCII code " << (int)ch << '\n';
    return 0;
}