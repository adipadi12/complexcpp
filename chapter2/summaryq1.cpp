#include <iostream>
using namespace std;

int readNumber(){
    std::cout << "Enter a number: ";
    int num{ };
    std::cin >> num;
    return num;
}

int writeAnswer(int x, int y){
    std::cout << "The answer is: " << x + y << endl;
}

int main()
{
    
    int x { readNumber() };
    int y { readNumber() };
    writeAnswer(x,y);
    return 0;
}