#include <bits/stdc++.h>

using namespace std;

vector<char> arr(256);

void transform(string &a)
{
    for (auto &x : a)
        x = arr[x];
}

int main()
{
    for (int x = 0; x < 27; x++)
    {
        if (x < 26)
            scanf(" %c", &arr[x + 'A']);
        else
            scanf(" %c", &arr['_']);
    }
    int n;
    scanf("%i", &n);
    string s;
    cin>>s;
    map<string,int> mp;
    int c = 0;
    while (n)
    {
        if (mp.count(s))
            n %= c - mp[s];   
        mp[s] = c++;
        n--;
        transform(s);
    }
    cout<<s<<endl;
}
