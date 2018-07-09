#include <bits/stdc++.h>

using namespace std;

double f(double m, double k, double p, double x){
 return m*x + k*p/m;
}

int main() {
 double k,p,x;cin >> k >> p >> x;
 
 double best = DBL_MAX;
 
 for(int m=1;f(m,k,p,x) < best;m++){
  best = f(m,k,p,x);
 }
 cout.setf(ios::showpoint);
 cout << setprecision(3) << fixed << best<<"\n";
}
