#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> ar(n);
    for (auto &x : ar)
        scanf("%i", &x);
    int a, b, ma = 0, mai = 0;
    scanf("%i%i", &a, &b);
    sort(ar.begin(), ar.end());
    b -= !(b&1);
    a += !(a&1);
    for (int x = 0; x < n-1; x++)
    {
        int m = ar[x]+ar[x+1]>>1;
        if (!(m&1))
        {
            if (abs(ar[x]-m) > abs(ar[x+1]-m))
                m--;
            else
                m++;
        }
        if (m < a)
            m = a;
        else if (m > b)
            m = b;
        if (m < ar[x] || m > ar[x+1])
            continue;
        if (min(abs(ar[x]-m), abs(ar[x+1]-m)) > ma)
            ma = min(abs(ar[x]-m), abs(ar[x+1]-m)), mai = m;        
    }
    if (b-ar.back() > ma)
        mai = b, ma = abs(ar.back()-(b-!(b&1)));
    if (ar[0]-a > ma)
        mai = a, ma = abs(ar[0]-(a+!(a&1)));
    cout<<mai;
}
