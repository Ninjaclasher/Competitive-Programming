#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l, r, gl, gr;
    long long c = 0;
    scanf("%i%i", &n, &gl);
    gr = gl;
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i", &l, &r);
        if (l <= gl)
        {
            if (r >= gl)
                gr = min(gr, r);
            else
            {
                c += gl-r;
                gr = gl;
                gl = r;
            }
        }
        else if (r >= gr)
        {
            if (l <= gr)
                gl = max(gl, l);
            else
            {
                c += l-gr;
                gl = gr;
                gr = l;
            }
        }
        else if (l > gl && r < gr)
            gl = l, gr = r;
    }
    printf("%lli\n", c);
}
