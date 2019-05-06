#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 0; x < n/2; x++)
        cout<<x+1<<" "<<n-x<<" ";
    if (n&1)
        cout<<n/2+1<<endl;
}
