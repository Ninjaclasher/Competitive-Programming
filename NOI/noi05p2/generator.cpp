#include <bits/stdc++.h>

using namespace std;

const int MINN = 1;
const int MAXN = 4;

const int MINM = 1;
const int MAXM = 3;

const int batch = 1;
const int start_case = 0;
const int num_cases = 300;

static inline __attribute__((always_inline)) int gen(int lower, int upper){return rand()%(upper-lower+1)+lower;}
static inline __attribute__((always_inline)) long long gen(long long lower, long long upper){return ((long long)rand()<<21^(long long)rand()<<21^(long long)rand())%(upper-lower+1)+lower;}
static inline __attribute__((always_inline)) void mkdir(string name){system(("mkdir " + name + " >/dev/null 2>/dev/null").c_str());}
static inline __attribute__((always_inline)) void init(){srand(time(NULL));mkdir("cases/");mkdir("cases/batch" + to_string(batch));}

int main()
{
    init();
    ofstream out;
    for (int u = start_case; u < start_case+num_cases; u++)
    {
        string file = "cases/batch" + to_string(batch) + "/" + to_string(u);
        out.open(file + ".in");
        int n = gen(MINN, MAXN), m = gen(MINM, MAXM);
        out<<n<<" "<<m<<endl;
        for (int x = 0; x < n; x++)
            out<<gen(-10, 10)<<" ";
        out<<endl;
        while (m--)
        {
            int op = gen(0, 5);
            switch(op)
            {
                case 0:{
                    int i = gen(1, n);
                    int l  = gen(0, n-i);
                    out<<"DELETE "<<i<<" "<<l<<endl;
                    n -= l;
                break;}
                case 1:{
                    int i = gen(0, n), l = gen(0, MAXN);
                    out<<"INSERT "<<i<<" "<<l<<" ";
                    for (int x = 0; x < l; x++)
                        out<<gen(-10, 10)<<" ";
                    out<<endl;
                    n += l;
                break;}
                case 2:{
                    int i = gen(1, n);
                    int l = gen(0, n-i+1);
                    out<<"MAKE-SAME "<<i<<" "<<l<<" "<<gen(-10, 10)<<endl;
                break;}
                case 3:{
                    int i = gen(1, n);
                    int l = gen(0, n-i+1);
                    out<<"REVERSE "<<i<<" "<<l<<endl;
                break;}
                case 4:{
                    int i = gen(1, n);
                    int l = gen(0, n-i+1);
                    out<<"GET-SUM "<<i<<" "<<l<<endl;
                break;}
                case 5:{
                    out<<"MAX-SUM"<<endl;
                break;}
                default:
                    abort();
            }
        }
        out.close();
        out.open(file + ".out");
        for (int x = 0; x < 1000; x++)
            out<<x<<"\n";
        out.close();
        system(("./brute.run < " + file + ".in > " + file + ".out").c_str());
    }
}
