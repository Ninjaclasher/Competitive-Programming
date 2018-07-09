#include <bits/stdc++.h>

using namespace std;


int main() 
{
    int a, b, c, d, e, f;
    scanf("%i%i%i%i%i%i", &a, &b, &c, &d, &e, &f);
    printf("%c", ((a <= d && b <= e && c <= f) || 
                  (a <= d && b <= f && c <= e) ||
                  (a <= f && b <= d && c <= e) ||
                  (a <= e && b <= d && c <= f) || 
                  (a <= e && b <= f && c <= d) || 
                  (a <= f && b <= e && c <= d)) ? 
                  'Y' : 'N' );
    return 0;
}
