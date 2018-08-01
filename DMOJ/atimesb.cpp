#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
const int L = 21;
const int M = (1<<L);
const complex<double> W(cos(2*PI/M), sin(2*PI/M));

int rev (int x)
{
    int ret = 0;
    for (int i = 0; i < L; i++)
    {
        ret <<= 1;
        ret |= x & 1;
        x >>= 1;
    }
    return ret;
}


void FFT(vector<complex<double>> &arr, bool inv = false)
{
    vector<complex<double>> ww(L);
    ww[L-1] = W;
    if (inv)
        ww[L-1] = pow(W, -1);
    for (int x = L-2; x >= 0; x--)
        ww[x] = ww[x+1]*ww[x+1];
    for (int x = 0; x < M; x++)
    {
        int y = rev(x);
        if (x < y)
            swap(arr[x], arr[y]);
    }
    for (int i = 0, m = 2; m <= M; m<<=1, i++)
    {
        int mm = m>>1;
        for (int off = 0; off < M; off += m)
        {
            complex<double> x(1, 0);
            for (int j = off; j < off+mm; j++)
            {
                auto a = arr[j], b = x*arr[j+mm];
                arr[j] = a + b;
                arr[j+mm] = a - b;
                x *= ww[i];
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    vector<complex<double>> aa(M), bb(M), cc(M);
    string a, b;
    cin>>a>>b;
    for (int x = 0; x < a.length(); x++)
        aa[x+(M-a.length())] = complex<double>(a[x]-'0', 0);
    for (int x = 0; x < b.length(); x++)
        bb[x+(M-b.length())] = complex<double>(b[x]-'0', 0);
    FFT(aa);
    FFT(bb);
    for (int x = 0; x < M; x++)
        cc[x] = aa[x]*bb[x];
    FFT(cc, true);
    for (int x = 0; x < M; x++)
        cc[x] /= M;
    vector<long long> ret(M);
    for (int x = 0; x < M; x++)
        ret[x] = round(cc[x].real());
    for (int x = M-2; x >= 0; x--)
        ret[x] += ret[x+1]/10, ret[x+1]%=10;
    int pr = 0;
    for (int x = 0; x < M-1; x++)
        if (ret[x] || pr)
            printf("%lli", ret[x]), pr = 1;
    if (!pr)
        printf("0");
}


