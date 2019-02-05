#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin>>a>>b;
    if (a.size() != 3 || b.size() != 7 || (a != "416" && a != "647" && a != "437"))
        cout<<"invalid\n";
    else if (a != "416")
        cout<<"valueless\n";
    else
        cout<<"valuable\n";
}
