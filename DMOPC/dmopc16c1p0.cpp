#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, c;
    scanf("%i%i", &w, &c);
    cout<<"C.C. is ";
    if (w == 3 && c >= 95)
        cout<<"absolutely";
    else if (w == 1 && c <= 50)
        cout<<"fairly";
    else
        cout<<"very";
    cout<<" satisfied with her pizza.\n";
}
