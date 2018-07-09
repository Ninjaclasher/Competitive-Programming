#include <iostream>

using namespace std;

int main()
{
    int y;
    cin >> y;
    int c = 0;
    if (y!= 1)
    {
        do
        {
            if  (y % 2 == 1)
                y = y * 3 + 1;
            else
                y = y/ 2;
            c++;
        }
        while (y > 1);
    }
    cout <<c;
}
