#include <stdio.h>
int main()
{
    int n, a = 0;
    scanf("%i", &n);
    char s[n];
    scanf("%15s", s);
    for (int x = 0; x < n; x++)
    {
        if (s[x] == 'A') a++; 
        else a--;
    }
    if (a > 0) printf("%c", 'A');
    else if (a < 0) printf("%c", 'B');
    else printf("%s", "Tie");
}
