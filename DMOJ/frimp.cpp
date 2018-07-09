#include <bits/stdc++.h>

using namespace std;

vector<string> split(string str, char c)
{
    vector<string> ss;
    string tmp = "";
    for (auto &x : str)
    {
        if (x == c)
        {
            if (!tmp.empty())
                ss.push_back(tmp);
            tmp = "";
        }
        else
            tmp += x;
    }
    if (!tmp.empty())
        ss.push_back(tmp);
    return ss;
}

bool vow(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

bool cmp(string a, string b)
{
    int aa = 0, bb = 0;
    if (a == "me" || a == "te" || a == "moi" || a == "toi" || a == "nous" || a == "vous" || a == "lui" || a == "leur")
        aa = 1;
    else if (a == "y")
        aa = 2;
    else if (a == "en")
        aa = 3;
    if (b == "me" || b == "te" || b == "moi" || b == "toi" || b == "nous" || b == "vous" || b == "lui" || b == "leur")
        bb = 1;
    else if (b == "y")
        bb = 2;
    else if (b == "en")
        bb = 3;
    return aa <= bb;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin>>n;
    while(n--)
    {
        do getline(cin, s); while(s.empty());
        vector<string> ss = split(s, ' ');
        if (ss[0].back() == ':')
            ss[0].pop_back();
        if (ss[ss.size()-1].back() == '.')
            ss[ss.size()-1].pop_back();
        string verb = ss.back();
        ss.pop_back();
        auto it = find(verb.begin(), verb.end(), '\'');
        if (it != verb.end() && vow(*(it+1)))
        {
            ss.push_back(verb[0] + string("e"));
            verb = verb.substr(it - verb.begin() + 1, verb.size());
        }
        if (ss[0].back() == 'r' && ss[0][ss[0].size() - 2] == 'e' && ss[1] == "Tu" && verb.back() == 's')
            verb.pop_back();
        verb[0] = toupper(verb[0]);
        cout<<verb;
        if (ss.size() > 2)
        {
            cout<<"-";
            reverse(ss.begin(), ss.end());
            ss.pop_back();
            ss.pop_back();
            for (auto &x : ss)
            {
                auto it = find(x.begin(), x.end(), '\'');
                if (it != x.end() && vow(*(it+1)))
                {
                    ss.push_back(x[0] + string("e"));
                    x = x.substr(it-x.begin()+1, x.size());
                }
            }        

            sort(ss.begin(), ss.end(), cmp);
            for (int q = 0; q < ss.size(); q++)
            {
                auto x = ss[q];
                if (x == "me" || x == "te")
                    x = x[0] + string("oi");
                if (q != ss.size()-1)
                {
                    if (vow(x.back()) && vow(ss[q+1][0]) && !(x.back() == 'y' && x.size() == 1))
                    {
                       while(!x.empty() && vow(x.back()))
                            x.pop_back();
                        cout<<x<<"\'"<<ss[++q];
                    }
                    else
                        cout<<x;
                }
                else
                    cout<<x;
                if (q != ss.size()-1)
                    cout<<"-";
            }
        }
        cout<<" !\n";
    }
}
