#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int a, k, c;
    scanf("%i", &a);
    scanf("%i", &k);
    c = a;
    for (int y = 1; y < k+1; y++)
        c += (a * pow(10, y));
    cout << c;
   return 0;
}
