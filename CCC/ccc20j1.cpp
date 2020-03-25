#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s, m, l;
    scanf("%i%i%i", &s, &m, &l);
    printf("%s\n", s + m * 2 + l * 3 >= 10 ? "happy" : "sad");
}
