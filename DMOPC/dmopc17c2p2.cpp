#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string a;
    cin>>a;
    vector<char> aa;
    for (auto &x : a)
        if (x == ')' && !aa.empty() && aa.back() == '(') aa.pop_back();
        else aa.push_back(x);

    int bb = aa.size(), cc = 0;
    if (bb > 2)
        printf("NO");
    else
    {
        while (!aa.empty() && aa.back() == '(')
            aa.pop_back(), cc++;
        printf("%s", (bb/2 + cc%2 < 2) ? "YES" : "NO");
    }
    return 0;
}
