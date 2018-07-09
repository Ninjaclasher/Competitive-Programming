#include <bits/stdc++.h>

using namespace std;

const int sq = 350;

struct qq
{
 int i, l, r;
 friend bool operator<(qq &a, qq &b)
 {
  return a.l/sq < b.l/sq || (a.l/sq == b.l/sq && (a.r < b.r || (a.r == b.r && a.l < b.l)));
 }
};



int main()
{
 int n, a, b, c, q;
 scanf("%i", &n);
 vector<int> aa(n);
 for (auto &x : aa)
  scanf("%i", &x);
 scanf("%i", &q);
 vector<qq> qqq(q);
 vector<int> ans(q);
 vector<int> freq(100001);
 for (int x = 0; x < q; x++)
  scanf("%i%i", &qqq[x].l, &qqq[x].r), qqq[x].i = x, qqq[x].l--, qqq[x].r--;
 sort(qqq.begin(), qqq.end());
 c = 0;
 int l = qqq[0].l, r = qqq[0].r, p = -1;
 for (int x = 0; x < q; x++)
 {
  auto cc = qqq[x];
  if (p != cc.l/sq)
  {
   c = 0;
   fill(freq.begin(), freq.end(), 0);
   l = r = qqq[x].l;
   p = cc.l/sq;
  }
  for (; l < cc.l; l++)
  {
   int bef = freq[aa[l]];
   freq[aa[l]]--;
   int cur = freq[aa[l]];
   if (bef && cur && (cur&1))
    c--;
   else if (bef && cur && !(cur&1))
    c++;
  }
  for (l--; l >= cc.l; l--)
  {
   int bef = freq[aa[l]];
   freq[aa[l]]++;
   int cur = freq[aa[l]];
   if (bef && cur && (cur&1))
    c--;
   else if (bef && cur && !(cur&1))
    c++;
  }
   for (l++; r <= cc.r; r++)
  {
   int bef = freq[aa[r]];
   freq[aa[r]]++;
   int cur = freq[aa[r]];
   if (bef && cur && (cur&1))
    c--;
   else if (bef && cur && !(cur&1))
    c++;
  }
  ans[cc.i] = c;
 }
 for (int x = 0; x < q; x++)
  printf("%i\n", ans[x]);
}
