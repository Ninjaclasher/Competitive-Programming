#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int k;
    scanf("%i", &k);
    string a;
    cin>>a;
    for (int x = 0; x < a.size(); x++)
        printf("%c", (a[x]-'A'-((x+1)*3+k)+52)%26+'A');
    return 0;
}
