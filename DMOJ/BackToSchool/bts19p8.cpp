#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1);

void check(int n)
{
    if (n == -400)
        exit(0);
}

void double_check(bool exp)
{
    if (!exp)
        throw logic_error("");
}

int query(long long A_buy, long long A_sell, long long B_buy, long long B_sell, long long P)
{
    printf("? %lli %lli %lli %lli %lli\n", A_buy, A_sell, B_buy, B_sell, P);
    fflush(stdout);
    int ans;
    scanf("%i", &ans);
    check(ans);
    return ans;
}

pair<int,int> compare(int j, int k)
{
    printf("C %i %i\n", j, k);
    fflush(stdout);
    pair<int,int> ans;
    scanf("%i", &ans.first);
    check(ans.first);
    scanf("%i", &ans.second);
    check(ans.second);
    return ans;
}

void check_answer(vector<pair<int,int>> ans)
{
    printf("!\n");
    for (auto &x : ans)
        printf("%i %i\n", x.first, x.second);
    fflush(stdout);
}

array<long long,3> convertToStandard(array<array<long long,2>,2> plane)
{
    return array<long long,3>{
        plane[1][0], plane[1][1], plane[0][0] * plane[1][0] + plane[0][1] * plane[1][1]
    };
}

array<long long,2> rotate(array<long long,2> v, array<long long,2> p, long double theta)
{
    return array<long long,2>{
        (long long)round(p[0] + (v[0] - p[0]) * cos(theta) - (v[1] - p[1]) * sin(theta)),
        (long long)round(p[1] + (v[0] - p[0]) * sin(theta) + (v[1] - p[1]) * cos(theta)),
    };
}

long long SCALE = 9'999'999'999;
long long HI = 1'000'000'000'000'000'000;

int curDay = 1;
int n;
set<pair<int,int>> S;

int ask(array<long long,3> plane)
{
    long long A_buy = plane[0] < 0 ? -plane[0] : 0;
    long long A_sell = plane[0] > 0 ? plane[0] : 0;
    long long B_buy = plane[1] < 0 ? -plane[1] : 0;
    long long B_sell = plane[1] > 0 ? plane[1] : 0;
    long long P = plane[2];
    curDay += 1;
    return query(A_buy, A_sell, B_buy, B_sell, P);    
}

int cmp(int j, int k, int y=-1)
{
    curDay += 1;
    pair<int,int> ret = compare(j, k);
    return ret.first == y ? ret.second : ret.first;
}

array<array<long long,2>,2> findMedianPlane()
{
    long long l = -SCALE, r = SCALE;
    array<long long,2> norm = {1, 0};
    array<long long,2> p = {0, 0};
    while (l <= r)
    {
        long long m = (l+r)>>1;
        p[0] = m;
        int ret = ask(convertToStandard({p, norm}));
        if (ret >= 0)
            l = m + 1;
        else
            r = m - 1;
    }
    p[0] = r;
    int ret = ask(convertToStandard({p, norm}));
    double_check(ret == 0);
    int savedDay = curDay - 1;
    ask(convertToStandard({array<long long,2>{p[0] + 1, p[1]}, array<long long,2>{-norm[0], -norm[1]}}));
    p[1] = cmp(savedDay, curDay - 1);
    double_check(p[1] != -1);
    return {array<long long,2>{p[0] + 1 - n%2, p[1]}, array<long long,2>{-norm[0], -norm[1]}};
}

array<array<long long,2>,2> adjustPlane(array<array<long long,2>,2> plane)
{
    int ret = ask(convertToStandard(plane));
    if (ret == 0)
        return plane;
    auto norm = plane[1];
    long double ang = atan2(norm[1], norm[0]) * 2;
    if (!(-PI <= ang && ang <= PI))
        ret *= -1;
    return {array<long long,2>{plane[0][0] + ret, plane[0][1]}, plane[1]};
}

array<array<long long,2>,2> windmill(array<array<long long,2>,2> plane)
{
    auto plane2 = adjustPlane(plane);
    int ret = ask(convertToStandard(plane2));
    double_check(ret == 0);
    int savedDay1 = curDay - 1;
    ask(convertToStandard({plane2[0], array<long long,2>{-plane2[1][0], -plane2[1][1]}}));
    int savedDay2 = curDay - 1;
    array<long long,2> p = plane[0];
    array<long long,2> norm = plane[1];

    long long l = 0, r = HI;
    long double baseAng = atan2(norm[1], norm[0]);
    while (l < r)
    {
        long long m = (l+r)>>1;
        long double ang = baseAng + (long double)m / HI * PI;
        long long x = round(SCALE * cos(ang));
        long long y = round(SCALE * sin(ang));
        ask(convertToStandard({p, array<long long,2>{-x, -y}}));
        int res1 = cmp(savedDay1, curDay - 1, p[1]);
        ask(convertToStandard({p, array<long long,2>{x, y}}));
        int res2 = cmp(savedDay2, curDay - 1, p[1]);
        if(res1 != -1 || res2 != -1)
            r = m;
        else
            l = m+1;
    }
    long double ang = baseAng + (long double)l / HI * PI;
    long long x = round(SCALE * cos(ang));
    long long y = round(SCALE * sin(ang));
    auto std1 = convertToStandard({p, array<long long,2>{-x, -y}});
    auto std2 = convertToStandard({p, array<long long,2>{x, y}});
    ask(std1);
    int res1 = cmp(savedDay1, curDay - 1, p[1]);
    ask(std2);
    int res2 = cmp(savedDay2, curDay - 1, p[1]);
    double_check((res1 == -1 || res2 == -1) && (res1 != -1 || res2 != -1));
    int res = res1 != -1 ? res1 : res2;
    auto std = res1 != -1 ? std1 : std2;
    int b = res;
    long double tmp = (long double)(std[2] - std[1] * b) / (long double)std[0];
    long long a = b > p[1] ? ceil(tmp) : floor(tmp);
    auto v = rotate({p[0] - a, p[1] - b}, {0, 0}, res1 == -1 ? -PI / 2 : PI / 2);
    std = convertToStandard({array<long long,2>{a, b}, v});
    double_check(p[0] * std[0] + p[1] * std[1] == std[2]);
    ang = atan2(v[1], v[0]) + 1e-5;
    v[0] = round(SCALE * cos(ang));
    v[1] = round(SCALE * sin(ang));
    return {array<long long,2>{a, b}, v};
}

void solve()
{
    auto plane = findMedianPlane();
    S.insert({plane[0][0], plane[0][1]});
    while (S.size() < n)
    {
        plane = windmill(plane);
        S.insert({plane[0][0], plane[0][1]});
    }
    vector<pair<int,int>> ans;
    for (auto &x : S)
        ans.push_back(x);
    check_answer(ans);
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        curDay = 1;
        S.clear();
        scanf("%i", &n);
        check(n);
        try
        {
            solve();
        }
        catch (logic_error &le)
        {
            vector<pair<int,int>> ans;
            for (int x = 0; x < n; x++)
                ans.push_back({1, 1});
            check_answer(ans);
        }
    }
}
