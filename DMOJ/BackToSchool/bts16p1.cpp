#include <iostream>
#include <limits>
#include <string>
#include <istream>

using namespace std;

bool isLower (char w)
{
    if (int(w) >= int('a') && int(w) <= int('z'))
        return true;
    else
        return false;
}
bool isUpper (char e)
{
    if (int(e) >= int('A') && int(e) <= int('Z'))
        return true;
    else
        return false;
}

int main()
{
    string a;
    getline(cin,a);
    int lengths = a.length();
    int l = 0;
    string output = "";
    for (int d = 0; d <= lengths; d++)
    {
        if (isLower(a[d]))
            l++;
        if (isUpper(a[d]))
            l--;
    }
    for (int s = 0; s < lengths; s++)
    {
        if (l > 0)
            output += tolower(a[s]);
        if (l < 0)
            output += toupper(a[s]);
    }
    if (l == 0)
        output = a;

    cout << output <<endl;
}
