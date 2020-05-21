#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    assert(1 <= n && n <= 100000);
    string s;
    cin>>s;
    assert(n == s.length());
    deque<char> ans;
    for (auto &x : s)
    {
        if (ans.empty())
            ans.push_back(x);
        else if (x <= ans.front())
            ans.push_front(x);
        else
            ans.push_back(x);
    }
    for (auto &x : ans)
        printf("%c", x);
    printf("\n");
}
