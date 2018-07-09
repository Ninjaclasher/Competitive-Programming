#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int k, m, a;
    scanf("%i%i", &k, &m);
    vector<int> aa (k+1);
    int s = 0;
    generate(aa.begin(), aa.end(), [&s](){return s++;});
    while (m--)
    {
        scanf("%i", &a);
        for (int x = a; x < aa.size(); x+=a-1)
            aa.erase(aa.begin()+x);
    }
    for (int x = 1; x < aa.size(); x++)
        printf("%i\n", aa[x]);
    return 0;
}
