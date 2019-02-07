#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    scanf("%d:%d:%d", &a, &b, &c);
    scanf("%d:%d:%d", &d, &e, &f);
    printf("%i\n", (d-a) * 3600 + (e-b) * 60 + (f-c));
}
