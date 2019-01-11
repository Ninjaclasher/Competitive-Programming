#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    list<long double> arr;
    while (n--)
    {
        long double a;
        scanf("%Lf", &a);
        arr.push_back(a);
    }
    int t, a, b, c, d;
    for (scanf("%i", &t); t != 77; scanf("%i", &t))
    {
        if (t == 99)
        {
            scanf("%i%i", &a, &b);
            auto it = arr.begin();
            for (int x = 0; x < a; x++)
                ++it;
            --it;
            arr.insert(it, (*it) * b / 100.0);
            *it *= (100-b)/100.0;
        }
        else if (t == 88)
        {
            scanf("%i", &a);
            auto it = arr.begin();
            for (int x = 0; x < a; x++)
                ++it;
            --it;
            //right
            auto it2 = it;
            ++it2;
            *it += *(it2);
            arr.erase(it2);
        }
        else
        {
            cout<<t<<endl;
            abort();
        }
    }
    for (auto &x : arr)
        printf("%i ", (int)round(x));
    printf("\n");
}

