#include <iostream>
using namespace std;

int main()
{
    double d1,d2;
    cout << "Enter a double value: ";
    cin >> d1;
    cout << "Enter a double value: ";
    cin >> d2;
    cout << "Enter +, -, *, or /: ";
    char op {};
    cin >> op;
    switch (op)
    {
        case '+':
            cout << d1+d2 << endl;
            break;
        case '-':
            cout << d1-d2 << endl;
            break;
        case '*':
            cout << d1*d2 << endl;
            break;
        case '/':
            if (d2 != 0) cout << d1/d2 << endl;
            else cout << "Error: Division by zero" << endl;
            break;
        default:
            break;
    }
}