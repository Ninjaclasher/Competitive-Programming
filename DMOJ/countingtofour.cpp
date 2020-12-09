#include <bits/stdc++.h>

using namespace std;

map<string,string> mp;

string run(string a)
{
    string ret = "";
    if (a.back() == '0')
        a.pop_back();
    if (a.length() == 3)
    {
        ret += mp[a.substr(2, 1) + ""] + "HUNDRED";
        a.pop_back();   
    }
    reverse(a.begin(), a.end());
    if (a.length() == 2)
    {
        if (a == "00")
            return ret;
        if (a[0] < '2')
        {
            if (a[0] == '0')
                ret += mp[a.substr(1, 1)];
            else
                ret += mp[a];
        }
        else
        {
            ret += mp[a.substr(0, 1) + "0"] + (a[1] == '0' ? "" : mp[a.substr(1, 1) + ""]);
        }
    }
    else
    {
        if (a == "0")
            return ret;
        ret += mp[a];
    }
    return ret;
}

int main()
{
    mp["0"] = "ZERO";
    mp["1"] = "ONE";
    mp["2"] = "TWO";
    mp["3"] = "THREE";
    mp["4"] = "FOUR";
    mp["5"] = "FIVE";
    mp["6"] = "SIX";
    mp["7"] = "SEVEN";
    mp["8"] = "EIGHT";
    mp["9"] = "NINE";
    mp["10"] = "TEN";
    mp["11"] = "ELEVEN";
    mp["12"] = "TWELVE";
    mp["13"] = "THIRTEEN";
    mp["14"] = "FOURTEEN";
    mp["15"] = "FIFTEEN";
    mp["16"] = "SIXTEEN";
    mp["17"] = "SEVENTEEN";
    mp["18"] = "EIGHTEEN";
    mp["19"] = "NINETEEN";
    mp["20"] = "TWENTY";
    mp["30"] = "THIRTY";
    mp["40"] = "FORTY";
    mp["50"] = "FIFTY";
    mp["60"] = "SIXTY";
    mp["70"] = "SEVENTY";
    mp["80"] = "EIGHTY";
    mp["90"] = "NINETY";
    string a;
    cin>>a;
    while (a != "4")
    {
        string ret = "";
        reverse(a.begin(), a.end());
        vector<string> st({"", "THOUSAND", "MILLION", "BILLION"});
        for (int x = 0, y=0; x < a.length(); x+=3, y++)
        {
            string tmp = run(a.substr(x, 3));
            if (tmp != "")
                ret = tmp + st[y] + ret;
        }
        ret = to_string(ret.size());
        printf("%s\n", ret.c_str());
        a = ret;
    }
}
