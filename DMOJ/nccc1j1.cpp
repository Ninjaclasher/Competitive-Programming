#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%i", &n);
    for (n++; ;n++)
    {
        string a = to_string(n);
        for (auto &x : a)
            if (x == '0')
                goto un;
        break;
        un:;
    }
    cout<<n<<"\n";
    return 0;
}
