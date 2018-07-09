#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n = 100;
    printf("%i\n", n);
    for (int x = 1; x < n; x++)
    {
        int one = x + ((x&1) ? 3 : 1);
        for (int y = x+1; y <= n; y++)
            printf("%i ", y == one || (x == 1 && y <= 3) ? 1 : 100);
        printf("\n");
    }
    //vector<pair<int,int>> aa;
    //for (int x = 2; x < 50; x+=2)
    //  aa.push_back({x, x+1});
    //for (int x = 1; x < 50; x+=2)
    //  aa.push_back({x, x+3});
    //for (auto &x : aa)
    //  cout<<x.first<<" "<<x.second<<endl;
//  cout<<"5\n1 2 3 4\n10 9 8\n7 6\n5\n";
//  cout<<"4\n1 1 1\n1 100\n100\n";
//cout<<"5\n1 1 1 1\n1 100 100\n100 100\n1\n";
//cout<<"6\n1 1 1 1 1\n1 100 100 100\n100 100 1\n1 100\n100\n";

}

/*

4
1 1 2
1 100
100

*/

/*

5
1 1 1 1
1 100 100
100 100
1

6
1 1 1 1 1
1 100 100 100
100 100 1
1 100
100
*/
