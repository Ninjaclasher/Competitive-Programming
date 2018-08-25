#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    scanf("%i%i", &a, &b);
    string n1, n2;
    cin>>n1>>n2;
    map<char,int> mp;
    reverse(n1.begin(), n1.end());
    for (int x = 0; x < a; x++)
        mp[n1[x]] = 0;
    for (int x = 0; x < b; x++)
        mp[n2[x]] = 1;
    n1 += n2;
    int t;
    scanf("%i", &t);
    while (t--)
    {
        for (int x = 0; x < n1.length()-1; x++)
            if (mp[n1[x]] == 0 && mp[n1[x+1]] == 1)
                swap(n1[x], n1[x+1]), x++;
    }
    cout<<n1<<"\n";
}
