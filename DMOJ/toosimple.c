#include <stdio.h>

#define put(...) puts(#__VA_ARGS__)

int main()
{
    put(Hello, World!);
}
