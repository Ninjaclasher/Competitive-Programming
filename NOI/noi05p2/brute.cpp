#include <bits/stdc++.h>

using namespace std;

char op[13];

int main()
{
    int n, m, i, l;
    char t;
    scanf("%i%i", &n, &m);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    while (m--)
    {
//       for (auto &x : arr)
//            cout<<x<<" ";
//        cout<<endl;

        scanf(" %s", op);
        t = op[2];
        if (t != 'X')
        {
            scanf("%i%i", &i, &l);
            if (!l)
            {
                if (t == 'T')
                    printf("0\n");
                continue;
            }
            //INSERT
            if (t == 'S')
            {
                vector<int> ne;
                for (int x = 0; x < i; x++)
                    ne.push_back(arr[x]);
                for (int x = 0; x < l; x++)
                {
                    int a;
                    scanf("%i", &a);
                    ne.push_back(a);
                }
                for (int x = i; x < n; x++)
                    ne.push_back(arr[x]);
                arr = ne;
                n = arr.size();
                continue;
            }
            switch(t)
            {
                //DELETE
                case 'L':
                {
                    vector<int> ne;
                    --i;
                    for (int x = 0; x < i; x++)
                        ne.push_back(arr[x]);
                    for (int x = i+l; x < n; x++)
                        ne.push_back(arr[x]);
                    arr = ne;
                    n = arr.size();
                }
                break;
                //MAKE-SAME
                case 'K':
                {
                    int a;
                    scanf("%i", &a);
                    --i;
                    for (int x = 0; x < l; x++)
                        arr[x+i] = a;
                }
                break;
                //REVERSE
                case 'V':
                {
                    --i;
                    for (int x = 0; x < l/2; x++)
                        swap(arr[i+x], arr[i+l-x-1]);
                }
                break;
                //GET-SUM
                case 'T':
                {
                    --i;
                    long long sum = 0;
                    for (int x = 0; x < l; x++)
                        sum += arr[x+i];
                    cout<<sum<<"\n";
                }
                break;
                default:
                    abort();
            }
        }
        else
        {
            long long ma = INT_MIN;
            for (int x = 0; x < n; x++)
            {
                for (int y = x; y < n; y++)
                {
                    long long s = 0;
                    for (int u = x; u <= y; u++)
                        s += arr[u];
                    ma = max(ma, s);
                }
            }
            cout<<ma<<"\n";
        }
    }
}
