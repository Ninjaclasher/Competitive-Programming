#include <bits/stdc++.h>

using namespace std;

int romanConverter(string roman)
{
    int value = 0;
    for (int x = 0; x < roman.length(); x++)
    {
        switch(roman[x])
        {
        case 'I':
            value++;
        break;
        case 'V':
            value += (roman[x-1] == 'I' ? 3 : 5);
        break;
        case 'X':
            value += (roman[x-1] == 'I' ? 8 : 10);
        break;
        case 'L':
            value += (roman[x-1] == 'X' ? 3 : 5) * 10;
        break;
        case 'C':
            value += (roman[x-1] == 'X' ? 8 : 10) * 10;
        break;
        case 'D':
            value += (roman[x-1] == 'C' ? 3 : 5) * 100;
        break;
        case 'M':
            value += (roman[x-1] == 'C' ? 8 : 10) * 100;
        break;
        }
    }
    return value;
}


int main() 
{
    string a;
    for (int x = 0; x < 5; x++)
    {
        cin>>a;
        printf("%i\n", romanConverter(a));
    }
    return 0;
}
