#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a;
    cin>>a;
    vector<int> arr(26);
    for (auto &x : a)
        arr[x-'a']++;
    sort(arr.rbegin(), arr.rend());
    printf("%i\n", a.size()-arr[0]-arr[1]);    
}
