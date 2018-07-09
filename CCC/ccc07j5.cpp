#include <bits/stdc++.h>

using namespace std;

vector<int> mot = {0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000};
int a, b, c, n, cc = 0;

void next(int p)
{
    if (mot[p] == 7000)
    {
        cc++;
        return;
    }
    for (int x = p+1; x < mot.size(); x++)
        if (mot[x]-mot[p] >= a && mot[x]-mot[p] <= b)
            next(x);
}

int main() 
{
    scanf("%i%i%i", &a, &b, &n);
    while (n--)
    {
        scanf("%i", &c);
        mot.push_back(c);
    }
    sort(mot.begin(), mot.end());
    next(0);
    printf("%i", cc);
    return 0;
}
