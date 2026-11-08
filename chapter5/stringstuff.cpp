#include <iostream>
#include <string.h>

int main()
{
    std::cout << "Enter Full Name: ";
    std::string name {};
    std::getline(std::cin >> std::ws, name); // entire line including spaces

    std::cout << "Enter your age: ";
    int age {};
    std::cin >> age;
    std::cout << "The sum of your age and length of your name is: " 
    << (static_cast<int>(name.length()) + age) << std::endl;
}