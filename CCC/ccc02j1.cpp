#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    switch(n)
    {
        case 0:
            cout <<" * * *\n*     *\n*     *\n*     *\n\n*     *\n*     *\n*     *\n * * *\n";
        break;
        case 5:
            cout <<" * * *\n*\n*\n*\n * * *\n      *\n      *\n      *\n * * *\n";
        break;
        case 9:
            cout <<" * * *\n*     *\n*     *\n*     *\n * * *\n      *\n      *\n      *\n * * *\n";
        break;
    }
    return 0;
}
