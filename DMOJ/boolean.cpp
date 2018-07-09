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

int main()
{
    string letter = "";
    getline(cin,letter);
    string str (letter);
    int len = str.length();
    bool prelen = true;
    if (len % 4 == 1)
    {
        len--;
        prelen = false;
    }
    len = len / 4;
    len--;
    if (prelen == false)
    {
        if (len % 2 == 0)
            cout << "False"<<endl;
        else
            cout << "True"<<endl;
    }
    else
    {
        if (len % 2 == 1)
            cout << "False"<<endl;
        else
            cout << "True"<<endl;  
    }
}
