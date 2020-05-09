#include <bits/stdc++.h>

using namespace std;

bool dis(int n)
{
    stringstream ss;
    ss << n;
    string s = ss.str();
    vector<bool> exist(10);
    for (auto &x : s)
    {
        if (exist[x-'0']) return false;
        else exist[x-'0'] = true;
    }
    return true;
}

int main() 
{
    int n;
    scanf("%i", &n);
    while (!dis(++n));
    printf("%i", n);
    return 0;
}
