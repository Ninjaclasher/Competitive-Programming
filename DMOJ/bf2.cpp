#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    int k;
    cin>>a;
    scanf("%i", &k);
    vector<string> aa;
    char e = 'z';
    for (int x = 0; x < a.size()-k; x++)
    {
        if (a[x] <= e)
        {
            if (a[x] < e)
            {
                aa.clear();
                e = a[x];
            }
            string b = "";
            for (int y = 0; y < k; y++)
                b+=a[x+y];
            aa.push_back(b);
        }
    }
    sort(aa.begin(), aa.end());
    cout<<aa[0];
    return 0;
}
