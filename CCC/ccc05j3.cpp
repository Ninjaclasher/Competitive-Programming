#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<pair<string,string>> dir;
    dir.push_back({"HOME", "\0"});
    string a, b;
    while (1)
    {
        cin>>a;
        cin>>b;
        dir.push_back({b, a});
        if (b == "SCHOOL")
            break;
    }
    for (int x = dir.size()-1; x >= 1; x--)
    {
        cout<<"Turn ";
        if (dir[x].second == "L")
            cout<<"RIGHT";
        else
            cout<<"LEFT";
        if (dir[x-1].first == "HOME")
            cout<<" into your HOME.\n";
        else
            cout<<" onto "<<dir[x-1].first<<" street.\n";
    }
}

