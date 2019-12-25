#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
const int MINN = 1;

const int MAXX = 100;
const int MINX = 1;

const int batch = 0;
const int start_case = 0;
const int num_cases = 1000;

static inline __attribute__((always_inline)) int gen(int lower, int upper){return rand()%(upper-lower+1)+lower;}
static inline __attribute__((always_inline)) long long gen(long long lower, long long upper){return (((long long)rand()<<16^(long long)rand())<<16^(long long)rand())%(upper-lower+1)+lower;}
static inline __attribute__((always_inline)) void mkdir(string name){system(("mkdir " + name + " >/dev/null 2>/dev/null").c_str());}
static inline __attribute__((always_inline)) void init(){srand(time(NULL));mkdir("cases/");mkdir("cases/batch" + to_string(batch));}

int main()
{
    init();
    ofstream out;
    for (int i = start_case; i < start_case+num_cases; i++)
    {
        string file = "cases/batch" + to_string(batch) + "/" + to_string(i);
        out.open(file + ".in");

        int n = gen(MINN, MAXN);
        int k = gen(1, n);
        out << n << " " << MAXX << " " << k << endl;
        for (int x = 0; x < n; x++)
            out << gen(MINX, MAXX) << " " << gen(MINX, MAXX) << endl;

        out.close();
        system(("./ioi16p6.run < " + file + ".in > " + file + ".out").c_str());
    }
}
