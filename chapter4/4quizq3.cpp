#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double distanceFallen(int time){
    return 9.8 * pow(time,2) / 2;
}
int main()
{
    double height;
    cout << "Enter height of tower in meters: ";
    cin >> height;
    for (int i = 0; i < height; i++)
    {
        if(distanceFallen(i) >= height){
            cout << "At " << i << " seconds, the ball is on the ground." << endl;
            break;
        } 
        
        cout << "At " << i << " seconds, the ball is at height: " << height - distanceFallen(i) << " meters" << endl;
        
    }
    return 0;
}