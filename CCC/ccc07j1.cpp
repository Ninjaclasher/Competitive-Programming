#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<int> a (3);
    scanf("%i%i%i", &a[0], &a[1], &a[2]);
    sort (a.begin(), a.end());
    printf("%i", a[1]);
    return 0;
}
