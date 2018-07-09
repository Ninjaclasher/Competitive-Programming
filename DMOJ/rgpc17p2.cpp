#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long int a,b,n,q,m,v,v1,v2;
    scanf("%llu%llu%llu",&n,&m,&q);
    unsigned long long int c[n];
    vector<int> ww (10000000);
    scanf("%llu", &c[0]);
    ww[c[0]]=0;
    for (int i = 1;i < n;i++) {
        scanf("%llu",&c[i]);
        ww[c[i]]=i;
        c[i]+=c[i-1];
    }
    for (int i =0;i <q;i++) {
        scanf("%llu%llu",&v1,&v2);
        if ((c[ww[v2]]- (ww[v1]-1 < 0 ? 0 : c[ww[v1]-1])) >= m*2) printf ("Enough\n");
        else printf ("Not enough\n");
    }
    return 0;
}
