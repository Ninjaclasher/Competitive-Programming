#include <bits/stdc++.h>

using namespace std;

typedef long long T;

struct fraction
{
    T num = 0, denom = 1;
    fraction(){}
    fraction (T a, T b=1) : num(a), denom(b) { normalize(); }

    void normalize()
    {
        T g = __gcd(num, denom);
        num /= g;
        denom /= g;
        if (denom < 0)
            denom = -denom, num = -num;
    }

    fraction reciprocal()
    {
        return fraction(denom, num);
    }
    fraction operator - ()
    {
        fraction ne(*this);
        ne.num = -ne.num;
        return ne;
    }
    friend fraction operator + (fraction a, fraction b)
    {
        return fraction(a.num * b.denom + b.num * a.denom, a.denom * b.denom);
    }
    friend fraction operator + (fraction a, T b)
    {
        return fraction(a.num + b * a.denom, a.denom);
    }
    friend fraction operator +=(fraction &a, fraction b)
    {
        return a = a+b;
    }
    friend fraction operator +=(fraction &a, T b)
    {
        return a = a+b;
    }
    friend fraction operator - (fraction a, fraction b)
    {
        return a + (-b);
    }
    friend fraction operator - (fraction a, T b)
    {
        return a + (-b);
    }
    friend fraction operator -=(fraction a , fraction b)
    {
        return a += -b;
    }
    friend fraction operator -=(fraction a, T b)
    {
        return a += -b;
    }
    friend fraction operator * (fraction a, fraction b)
    {
        return fraction(a.num * b.num, a.denom * b.denom);
    }
    friend fraction operator * (fraction a, T b)
    {
        return fraction(a.num * b, a.denom);
    }
    friend fraction operator *=(fraction &a, fraction b)
    {
        return a = a*b;
    }
    friend fraction operator *=(fraction &a, T b)
    {
        return a = a*b;
    }
    friend fraction operator / (fraction a, fraction b)
    {
        return a * b.reciprocal();
    }
    friend fraction operator / (fraction a, T b)
    {
        return fraction(a.num, a.denom * b);
    }
    friend fraction operator /=(fraction &a, fraction b)
    {
        return a = a/b;
    }
    friend fraction operator /=(fraction &a, T b)
    {
        return a = a/b;
    }
    friend bool operator < (fraction a, fraction b)
    {
        return a.num * b.denom < b.num * a.denom;
    }
    friend bool operator ==(fraction a, fraction b)
    {
        return a.num == b.num && a.denom == b.denom;
    }
    friend bool operator !=(fraction a, fraction b)
    {
        return !(a == b);
    }
    friend bool operator > (fraction a, fraction b)
    {
        return !(a < b || a == b);
    }
    friend bool operator <=(fraction a, fraction b)
    {
        return a < b || a == b;
    }
    friend bool operator >=(fraction a, fraction b)
    {
        return !(a < b);
    }
    friend ostream& operator <<(ostream &out, const fraction &a)
    {
        return out << a.num << " / " << a.denom;
    }
};

fraction abs(fraction a)
{
    return (a < 0) ? -a : a;
}

struct line
{
    fraction slope;
    fraction gety(int x)
    {
        return slope * x;
    }
    fraction getx(int y)
    {
        return slope.reciprocal() * y;
    }
    void inverse()
    {
        slope = slope.reciprocal();
    }
    void perpendicular()
    {
        inverse();
        slope = -slope;
    }
    bool neg() { return slope <= 0; }
    bool pos() { return slope >= 0; }
    friend bool operator<(line x, line y)
    {
        return x.slope < y.slope;
    }
};


int n, m;

fraction solve_quadrant_border_case(line a, line b)
{
    // orz wesley and zeyu
    return fraction(n) -  fraction(n) / (b.slope - a.slope + 1);
}

fraction solve_y_standard_case(line a, line b)
{
    // line a is the bounding line, optimal solution always hits intersection of line b and bounding box
    fraction b_intercept_x = b.getx(n);
    fraction k = n + b_intercept_x;
    fraction xx = k / (a.slope + 1);
    return xx - b_intercept_x;
}

fraction solve_x_standard_case(line a, line b)
{
    a.inverse();
    b.inverse();
    return solve_y_standard_case(b, a);
}

fraction solve_corner_case(line a, line b)
{
    // a intersects right bounding box
    // b intersects top bounding box
    fraction a_intersect_y = a.gety(n);
    fraction b_intersect_x = b.getx(n);
    if (a_intersect_y > b_intersect_x)
        return solve_y_standard_case(a, b);
    else
        return solve_x_standard_case(a, b);
}

fraction solve(vector<line> &arr)
{
    // edge cases
    if (arr.size() == 1)
        return n;
    // all lines are non-negative 
    if (arr[0].pos() && arr[m-1].pos())
        return n;
    // all lines are non-positive
    if (arr[0].neg() && arr[m-1].neg())
        return n;
    fraction ret(0);
    for (int x = 0; x < m-1; x++)
    {
        line cur = arr[x], nex = arr[x+1];
        // more casework :D
        if (cur.neg() && nex.pos())
            ret = max(ret, solve_quadrant_border_case(cur, nex));
        else
        {
            // move from Q4 to Q1
            if (nex.neg())
            {
                cur.slope *= -1;
                nex.slope *= -1;
                swap(cur, nex);
            }
            if (cur.slope > 1)
                ret = max(ret, solve_y_standard_case(cur, nex));
            else if (nex.slope > 1)
                ret = max(ret, solve_corner_case(cur, nex));
            else
                ret = max(ret, solve_x_standard_case(cur, nex));
        }
    }
    return ret;
}

int main()
{
    scanf("%i%i", &n, &m);
    vector<line> arr(m);
    for (auto &x : arr)
    {
        scanf("%lli%lli", &x.slope.num, &x.slope.denom);
        x.slope.normalize();
    }
    sort(arr.begin(), arr.end());
    fraction ma = solve(arr);
    for (auto &x : arr)
        x.perpendicular();
    sort(arr.begin(), arr.end());
    ma = max(ma, solve(arr));
    printf("%lli %lli\n", ma.num, ma.denom);
}
