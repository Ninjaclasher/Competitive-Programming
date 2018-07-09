#include <bits/stdc++.h>
#include <limits>

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main() 
{
    int n;
    int a = INT_MAX;
    cin >> n;
    int arr[n];
    for (int x = 0; x < n; x++)
        cin >>arr[x];
    qsort(arr, n, sizeof(int), compare);
    for (int x = 0; x < n-1; x++)
        a = min(abs(arr[x]-arr[x+1]), a);
    cout <<a;
    return 0;
}
