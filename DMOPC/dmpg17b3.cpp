#include <stdio.h>

int main() {
    int n, h, d, hf, df, htmp, c;
    scanf("%i%i%i", &n, &h, &d);
    for (int x = 0; x < n; x++)
    {
        c = 0;
        htmp = h;
        scanf("%i%i", &hf, &df);
        do
        {
            c++;
            hf -= d;
            if (hf <= 0) break;
            if (c%4 != 0)
                htmp -= df;
        }
        while (htmp > 0 && hf > 0);
        if (htmp <= 0) printf("Lose %i\n", c);
        else printf("Win %i\n", c);
    }
    return 0;
}
