#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr (n);
    for (int x = 0; x < n; x++)
        cin>>arr[x];
    sort(arr.begin(), arr.end());
    for (int x = 0; x < n; x++)
        cout<<arr[x]<<endl;
    return 0;
}
