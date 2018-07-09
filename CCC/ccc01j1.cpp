#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <limits>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

void s(int h, int r)
{
    for (int a = 1; a <= (h-1) * 2 + 1; a ++)
        cout <<"*";
    for (int a = 1; a <= (r*2) - ((h-1) * 2 + 1) * 2; a++)
        cout <<" ";
    for (int a = 1; a <= (h-1) * 2 + 1; a ++)
        cout <<"*";
    cout <<endl;
}


int main()
{
    int row;
    cin>>row;
    for (int x = 1; x <= (row -1)/2; x ++)
        s(x, row);
    for (int x = 1; x <= row * 2; x ++)
        cout <<"*";
    cout <<endl;
    for (int x = (row - 1)/2; x >=1; x--)
        s(x, row);
}
