#include <iostream>
using namespace std;
int main(){
    unsigned short x { 65535 }; // largest 16-bit 
    //unsigned value possible
    cout << "x was: " << x << endl;

    x = 65536; // one value above highest possible value
    cout << "x is now: " << x << endl;

    x = 65537;
    cout << "x is now: " << x << endl;


    unsigned short y{ 0 }; // largest 16-bit unsigned value possible
    std::cout << "y was: " << y << '\n';

    y = -1; // 65536 is out of our range, so we get modulo wrap-around
    std::cout << "y is now: " << y << '\n';

    y = -2; // 65537 is out of our range, so we get modulo wrap-around
    std::cout << "y is now: " << y << '\n';

    unsigned int z {2};
    unsigned int a { 3};
    cout << z-a << '\n';

    unsigned int u{ 2 };
	signed int s{ 3 };

	std::cout << u - s << '\n'; // 2 - 3 = 4294967295

    return 0;
    
}