#include <bits/stdc++.h>

using namespace std;

int main() 
{
    deque<int> minQ, maxQ;
    vector<int> aa (4000000);
    int n, k, l = 0;
    long long s = 0;
    scanf("%i%i", &n, &k);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &aa[x]);
        while (!maxQ.empty() && maxQ.back() < aa[x]) maxQ.pop_back();
        maxQ.push_back(aa[x]);
        while (!minQ.empty() && minQ.back() > aa[x]) minQ.pop_back();
        minQ.push_back(aa[x]);
        while (maxQ.front() - minQ.front() > k) 
        {
            if (minQ.front() == aa[l]) minQ.pop_front();
            if (maxQ.front() == aa[l]) maxQ.pop_front();
            l++;
        }
        s += x-l+1;
    }
    printf("%lli", s);
    return 0;
}
