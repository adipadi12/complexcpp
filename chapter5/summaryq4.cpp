// #include <iostream>
// #include <string_view>
// #include <string>

// int main()
// {
//     std::string name1{}, name2 {};
//     int age1, age2;

//     std::cout << "Enter the name of person #1: ";
//     std::getline(std::cin >> std::ws, name1);
//     std::cout << "Enter the age of " << name1 << ": ";
//     std::cin >> age1;
//     std::string_view name1vs = name1;

//     std::cout << "Enter the name of person #2: ";
//     std::getline(std::cin >> std::ws, name2);
//     std::cout << "Enter the age of " << name2 << ": ";
//     std::cin >> age2;
//     std::string_view name2vs = name2;

//     if (age1 > age2)
//     {
//         std::cout << name1vs << " (age " << age1 <<
//         ") is older than " << name2vs << " (age " << age2 << ")." << std::endl;
//     }
//     else
//     {
//         std::cout << name2vs << " (age " << age2 <<
//         ") is older than " << name1vs << " (age " << age1 << ")." << std::endl;
//     }
// }

#include <iostream>
#include <string>
#include <string_view>

std::string getName(int num)
{
    std::cout << "Enter the name of person #" << num << ": ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    return name;
}

int getAge(std::string_view sv)
{
    std::cout << "Enter the age of " << sv << ": ";
    int age{};
    std::cin >> age;

    return age;
}

void printOlder(std::string_view name1, int age1, std::string_view name2, int age2)
{
    if (age1 > age2)
        std::cout << name1 << " (age " << age1 <<") is older than " << name2 << " (age " << age2 <<").\n";
    else
        std::cout << name2 << " (age " << age2 <<") is older than " << name1 << " (age " << age1 <<").\n";
}

int main()
{
    const std::string name1{ getName(1) };
    const int age1 { getAge(name1) };

    const std::string name2{ getName(2) };
    const int age2 { getAge(name2) };

    printOlder(name1, age1, name2, age2);

    return 0;
}