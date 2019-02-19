#include <bits/stdc++.h>

using namespace std;

int n;
void run(vector<int> &a)
{
    vector<int> nxt;
    for (int x = n-1; x >= 0; x--)
    {
        if (a[x])
        {
            if (nxt.empty())
            {
                //lazy
                int y = x;
                while (y < n)
                    y += 2;
                y -= 2;
                nxt.push_back(y);
                a[x] = 0;
                a[y] = 1;
            }
            else
            {
                if ((nxt.back()-x)&1)
                {
                    a[nxt.back()] = 0;
                    a[x] = 0;
                    nxt.pop_back();
                }
                else
                {
                    int k = nxt.back()-2;
                    a[x] = 0;
                    a[k] = 1;
                    nxt.push_back(k);
                }
            }
        }
    }
}

int main()
{
    scanf("%i", &n);
    vector<int> a(n), b(n);
    char c;
    for (auto &x : a)
    {
        scanf(" %c", &c);
        x = (c == 'F');
    }
    for (auto &x : b)
    {
        scanf(" %c", &c);
        x = (c == 'F');
    }
    run(a);
    run(b);
    for (int x = 0; x < n; x++)
        if (a[x] != b[x])
            return 0 * printf("NO\n");
    printf("YES\n");
}
