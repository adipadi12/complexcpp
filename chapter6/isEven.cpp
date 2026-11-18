#include <iostream>
using namespace std;
#include <string>

constexpr bool isEven(int x)\
{
    return (x % 2 == 0);
}

int main()
{
    int x {};
    cout << "Enter value of x: ";
    cin >> x;
    string value = (isEven(x) == true) ? "even" : "odd";
    cout << x << " is " << value << endl;
}