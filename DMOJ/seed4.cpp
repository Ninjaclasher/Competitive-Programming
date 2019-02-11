#include <bits/stdc++.h>

using namespace std;

struct seg
{
    long long x, y, z;
    void reduce()
    {
        long long g = abs(__gcd(__gcd(x, y), z));
        x /= g;
        y /= g;
        z /= g;
    }
    friend bool operator<(seg a, seg b)
    {
        return a.x < b.x || (a.x == b.x && (a.y < b.y || (a.y == b.y && a.z < b.z)));
    }
    friend bool operator==(seg a, seg b)
    {
        return a.x == b.x && a.y == b.y && a.z == b.z;
    }
};

int main()
{
    long long a, b, c;
    int n;
    scanf("%lli%lli%lli", &a, &b, &c);
    scanf("%i", &n);
    vector<seg> arr(n);
    for (auto &x : arr)
    {
        scanf("%lli%lli%lli", &x.x, &x.y, &x.z);
        x.x -= a;
        x.y -= b;
        x.z -= c;
        x.reduce();
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    printf("%lu\n", arr.size());
}
