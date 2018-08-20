#include <bits/stdc++.h>

using namespace std;

vector<string> split(string &a, char c)
{
    vector<string> ret;
    string cur;
    for (auto &x : a)
    {
        if (x == c)
            ret.push_back(cur), cur = "";
        else
            cur += x;
    }
    if (cur != "")
        ret.push_back(cur);
    return ret;
}

int main()
{
    string in;
    for (getline(cin, in); in != "0"; getline(cin, in))
    {
        vector<string> tokens = split(in, ' ');
        for (int y = tokens.size()-1; y >= 0; y--)
        {
            if (tokens[y] == "+" || tokens[y] == "-")
            {
                tokens[y] = tokens[y+1] + " " + tokens[y+2] + " " + tokens[y];
                tokens.erase(tokens.begin()+y+2);
                tokens.erase(tokens.begin()+y+1);                
            }
        }
        cout<<tokens[0]<<"\n";
    }
}

