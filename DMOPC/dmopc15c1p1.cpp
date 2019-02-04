#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<pair<long double, string>> arr(n);
    for (auto &x : arr)
        cin>>x.second>>x.first;
    sort(arr.rbegin(), arr.rend());
    cout<<arr[0].second<<endl;
}
