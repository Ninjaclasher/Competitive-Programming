#include <bits/stdc++.h>

using namespace std;

typedef long long T;
const T MOD = 1000000007;
const bool PRIME_MOD = true;
#define LARGE_MOD (MOD >> 31) != 0

struct mod_int
{
    T val = 0;
    mod_int(){}
    mod_int(T v) : val(v) { normalize(); }

    void normalize()
    {
        // optimizable
        val %= MOD;
        if (val < 0)
            val += MOD;
    }

    mod_int inv() const
    {
        if (PRIME_MOD) return mod_int::pow(*this, MOD-2);
        throw logic_error("unimplemented");
    }
    mod_int operator - () const
    {
        mod_int ne(*this);
        ne.val = MOD - ne.val;
        ne.normalize();
        return ne;
    }

    explicit operator bool() const { return val; }
    explicit operator T() const { return val; }

    friend mod_int operator + (const mod_int a, const mod_int b) { return mod_int(a.val + b.val); }
    friend mod_int operator + (const mod_int a, const T b) { return mod_int(a.val + b); }
    template<class S>
    friend mod_int operator +=(mod_int &a, const S b) { return a = a+b; }
    friend mod_int operator ++(mod_int &a) { return a += 1; }
    friend mod_int operator ++(mod_int &a, int v) { mod_int tmp(a); ++a; return tmp; }

    template<class S>
    friend mod_int operator - (const mod_int a, const S b) { return a + (-b); }
    template<class S>
    friend mod_int operator -=(mod_int &a, const S b) { return a += -b; }
    friend mod_int operator --(mod_int &a) { return a -= 1; }
    friend mod_int operator --(mod_int &a, int v) { mod_int tmp(a); --a; return tmp; }

    friend mod_int operator * (const mod_int a, const mod_int b)
    {
#if LARGE_MOD
        return long_mult(a, b);
#else
        return mod_int(a.val * b.val);
#endif
    }
    friend mod_int operator * (const mod_int a, const T b) { return a * mod_int(b); }
    template<class S>
    friend mod_int operator *=(mod_int &a, const S b) { return a = a*b; }

    friend mod_int operator / (const mod_int a, const mod_int b) { return a * b.inv(); }
    friend mod_int operator / (const mod_int a, const T b) { return a / mod_int(b); }
    template<class S>
    friend mod_int operator /=(mod_int &a, const S b) { return a = a/b; }

    friend mod_int operator <<(const mod_int a, const T b) { return mod_int(a.val << b); }
    friend mod_int operator <<=(mod_int &a, const T b) { return a = a << b; }
    friend mod_int operator >>(const mod_int a, const T b) { return mod_int(a.val >> b); }
    friend mod_int operator >>=(mod_int &a, const T b) { return a = a >> b; }

    friend mod_int operator & (const mod_int a, const mod_int b) { return mod_int(a.val & b.val); }
    template<class S>
    friend mod_int operator & (const mod_int a, const S b) { return mod_int(a.val & b); }
    template<class S>
    friend mod_int operator &=(mod_int &a, const S b) { return a = a & b; }

    friend mod_int operator | (const mod_int a, const mod_int b) { return mod_int(a.val | b.val); }
    template<class S>
    friend mod_int operator | (const mod_int a, const S b) { return mod_int(a.val | b); }
    template<class S>
    friend mod_int operator |=(mod_int &a, const S b) { return a = a | b; }

    friend mod_int operator ^ (const mod_int a, const mod_int b) { return mod_int(a.val ^ b.val); }
    template<class S>
    friend mod_int operator ^ (const mod_int a, const S b) { return mod_int(a.val ^ b); }
    template<class S>
    friend mod_int operator ^=(mod_int &a, const S b) { return a = a ^ b; }

    friend bool operator==(const mod_int &a, const mod_int &b) { return a.val == b.val; }
    friend bool operator<(const mod_int &a, const mod_int &b) { return a.val < b.val; }
    friend bool operator<=(const mod_int &a, const mod_int &b) { return a < b || a == b; }
    friend bool operator>=(const mod_int &a, const mod_int &b) { return !(a < b); }
    friend bool operator>(const mod_int &a, const mod_int &b) { return !(a <= b); }
    friend bool operator!=(const mod_int &a, const mod_int &b) { return !(a == b); }
    template<class S>
    friend bool operator<(const S &a, const mod_int &b) { return mod_int(a) < b; }
    template<class S>
    friend bool operator>(const S &a, const mod_int &b) { return mod_int(a) > b; }
    template<class S>
    friend bool operator<=(const S &a, const mod_int &b) { return mod_int(a) <= b; }
    template<class S>
    friend bool operator>=(const S &a, const mod_int &b) { return mod_int(a) >= b; }
    template<class S>
    friend bool operator==(const S &a, const mod_int &b) { return mod_int(a) == b; }
    template<class S>
    friend bool operator!=(const S &a, const mod_int &b) { return mod_int(a) != b; }

    static mod_int long_mult(mod_int x, mod_int y)
    {
        mod_int result = 0;
        for (; y; x <<= 1, y >>= 1)
            if (y&1)
                result += x;
        return result;
    }
    template<class S>
    static mod_int pow(mod_int base, S exp)
    {
        mod_int result = 1;
        for (; exp; exp >>= 1, base *= base)
            if (exp&1)
                result *= base;
        return result;
    }
    static mod_int pow(mod_int base, mod_int exp) { return pow(base, exp.val); }

    friend ostream& operator <<(ostream &out, const mod_int &a) { return out << a.val; }
    friend istream& operator >>(istream &in, mod_int &a) { return in >> a.val; }
};

mod_int fac[200005];

mod_int choose(int n, int k)
{
    return fac[n] / fac[k] / fac[n-k];
}

mod_int run(int h, int w)
{
    return choose(h + w - 2, w - 1);
}

int main()
{
    fac[0] = 1;
    for (int x = 1; x < 200005; x++)
        fac[x] = fac[x-1] * x;
    int h, w, n;
    scanf("%i%i%i", &h, &w, &n);
    vector<pair<int,int>> arr(n);
    for (auto &x : arr)
        scanf("%i%i", &x.first, &x.second);
    sort(arr.begin(), arr.end());
    arr.push_back({h, w});
    vector<mod_int> dp(arr.size());
    for (int x = 0; x < arr.size(); x++)
    {
        dp[x] = run(arr[x].first, arr[x].second);
        for (int y = 0; y < x; y++)
            if (arr[y].first <= arr[x].first && arr[y].second <= arr[x].second)
                dp[x] -= dp[y] * run(arr[x].first - arr[y].first + 1, arr[x].second - arr[y].second + 1);
    }
    printf("%lli\n", dp[n].val);
}
