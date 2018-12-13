#include <bits/stdc++.h>

using namespace std;

const int MINN = 2;
const int MAXN = 12;

const int MINM = 2;
const int MAXM = 12;

const int MINV = 0;
const int MAXV = 4;

const int MINC = 0;
const int MAXC = 4;

const int batch = 1;
const int start_case = 0;
const int num_cases = 50;

static inline __attribute__((always_inline)) int gen(int lower, int upper){return rand()%(upper-lower+1)+lower;}
static inline __attribute__((always_inline)) long long gen(long long lower, long long upper){return ((long long)rand()<<21^(long long)rand()<<21^(long long)rand())%(upper-lower+1)+lower;}
static inline __attribute__((always_inline)) void mkdir(string name){system(("mkdir " + name + " >/dev/null 2>/dev/null").c_str());}
static inline __attribute__((always_inline)) void init(){srand(time(NULL));mkdir("cases/");mkdir("cases/batch" + to_string(batch));}

ofstream out;
void run()
{
    out<<" "<<gen(MINV, MAXV)<<" "<<gen(MINV, MAXV)<<" "<<gen(MINV, MAXV)<<endl;
}

int main()
{
    init();
    for (int i = start_case; i < start_case+num_cases; i++)
    {
        string file = "cases/batch" + to_string(batch) + "/" + to_string(i);
        out.open(file + ".in");
        out<<1<<endl;
        int n = gen(MINN, MAXN);
        out<<n<<" "<<gen(MINM, MAXM)<<endl;
        out<<gen(MINV, MAXV)<<" "<<gen(MINV, MAXV);
        run();
        out<<gen(1, 4)<<" "<<gen(1, 4);
        run();
        out<<gen(1, n)<<" "<<gen(1, n);
        run();
        out<<gen(1, n)<<" "<<gen(1, n);
        run();
        out<<gen(MINC, MAXC)<<" "<<gen(MINC, MAXC);
        run();
        out<<gen(MINC, MAXC)<<" "<<gen(MINC, MAXC);
        run();
        out.close();
        system(("./fhc15c2p4.run < " + file + ".in > " + file + ".out").c_str());
    }
}
