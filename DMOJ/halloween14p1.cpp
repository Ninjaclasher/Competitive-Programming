#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, k;
    return 0 * scanf("%i%i", &n, &k) * printf("%i", n < k ? k-n : min(k-(n%k), n%k));
}
