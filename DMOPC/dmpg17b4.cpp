#include <stdio.h>

int main() {
    for (int x = 1023; x > 0; x-=2)
        printf("%i\n", x);
    for (int x = 0; x < 1024; x+=2)
        printf("%i\n", x);
    return 0;
}
