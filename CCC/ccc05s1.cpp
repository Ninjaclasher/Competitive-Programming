#include <bits/stdc++.h>

using namespace std;

char ord(int n)
{
    return (char)(n+'0');
}

int main()
{
    int n;
    scanf("%i", &n);
    while (n--)
    {
        string a;
        cin>>a;
        string b;
        for (auto &x : a)
        {
            if (x == '-')
                continue;
            if (x <= '9')
                b.push_back(x);
            else
            {
                if (x <= 'C')
                    b.push_back(ord(2));
                else if (x <= 'F')
                    b.push_back(ord(3));
                else if (x <= 'I')
                    b.push_back(ord(4));
                else if (x <= 'L')
                    b.push_back(ord(5));
                else if (x <= 'O')
                    b.push_back(ord(6));
                else if (x <= 'S')
                    b.push_back(ord(7));
                else if (x <= 'V')
                    b.push_back(ord(8));
                else if (x <= 'Z')
                    b.push_back(ord(9));
            }
        }
        while (b.size() > 10)
            b.pop_back();
        for (int x = 0; x < 10; x++)
        {
            cout<<b[x];
            if (x == 2 || x == 5)
                cout<<"-";
        }
        cout<<"\n";
    }
}

