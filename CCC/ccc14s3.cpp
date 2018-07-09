#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int t, n, a;
    scanf("%i", &t);
    while(t--)
    {
        scanf("%i", &n);
        stack<int> c, b;
        int l = 0;
        for (int x = 0; x < n; x++)
        {
            scanf("%i", &a);
            c.push(a);
        }
        while (!c.empty())
        {
            int cc = c.top();
            c.pop();
            if (cc == l+1)
            {
                l = cc;
                while(!b.empty() && b.top() == l+1)
                {
                    l = b.top();
                    b.pop();
                }
                continue;
            }
            else
                b.push(cc);
        }
        while(!b.empty() && b.top() == l+1)
        {
            l = b.top();
            b.pop();
        }
        printf("%c\n", b.empty() ? 'Y' : 'N');
    }
    return 0;
}
