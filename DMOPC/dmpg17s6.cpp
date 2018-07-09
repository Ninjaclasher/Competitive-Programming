#include <bits/stdc++.h>

using namespace std;

string n, original;
vector<pair<char,int>> b, c;
int bracketPairs[200000];
int num, changes;
bool changed[200000], twoC[200000];

char opposite(char o)
{
    switch (o)
    {
    case '[': return ']';
    case ']': return '[';
    case '{': return '}';
    case '}': return '{';
    case '(': return ')';
    case ')': return '(';
    }
}

char alternative(char o, char i)
{
    if ((o == '[' && i == '(') || (o == '(' && i == '[')) return '{';
    if ((o == '(' && i == '{') || (o == '{' && i == '(')) return '[';
    if ((o == '{' && i == '[') || (o == '[' && i == '{')) return '(';
    if ((o == ']' && i == ')') || (o == ')' && i == ']')) return '}';
    if ((o == ')' && i == '}') || (o == '}' && i == ')')) return ']';
    if ((o == '}' && i == ']') || (o == ']' && i == '}')) return ')';
}

char alternative(char o)
{
    switch (o)
    {
    case '[': return '{';
    case '(': return '[';
    case '{': return '(';
    case ']': return '}';
    case ')': return ']';
    case '}': return ')';
    }
}

void bracketCorrect()
{
    for (int x = 0; x < num; x++)
    {
        switch (n[x])
        {
        case '[':
        case '{':
        case '(':
            b.push_back(make_pair(n[x], x));
            break;
        case ')':
        case '}':
        case ']':
            if (b.back().first != opposite(n[x]))
                c.push_back(make_pair(opposite(b.back().first), x));
            bracketPairs[b.back().second] = x;
            bracketPairs[x] = b.back().second;
            b.pop_back();
            break;
        }
    }
}

void validBracketChanged(int numChanged)
{
    if (!numChanged)
        return;
    string l = n;
    bool a = (numChanged == 1) ? false : true;
    label:
    b.clear();
    for (int x = 0; x < num; x++)
    {
        switch (n[x])
        {
        case '[':
        case '{':
        case '(':
            b.push_back(make_pair(n[x], x));
            break;
        case ')':
        case ']':
        case '}':
            if (!changed[x] && numChanged != 1 && !twoC[x] && a)
            {
                n[x] = alternative(n[x]);
                numChanged-=2;
                twoC[x] = twoC[bracketPairs[x]] = true;
            }
            else if (changed[x] && !twoC[x] && !a)
            {
                n[x] = alternative(original[x], opposite(original[bracketPairs[x]]));
                changed[x] = changed[bracketPairs[x]] = false;
                twoC[x] = twoC[bracketPairs[x]] = true;
                numChanged--;
            }
            n[bracketPairs[x]] = opposite(n[x]);
            b.pop_back();
            break;
        }
        if (numChanged == 0)
            return;
    }
    if (numChanged != 0 && a)
    {
        a = false;
        goto label;
    }
}

int main()
{
    cin>>num>>changes>>n;
    original = n;
    bracketCorrect();
    if (c.size() > changes || (c.empty() && changes%2))
        printf("impossible");
    else
    {
        for (int x = 0; x < c.size(); x++)
        {
            n[c[x].second] = c[x].first;
            changed[c[x].second] = changed[bracketPairs[c[x].second]] = true;
        }
        changes-=c.size();
        if (changes % 2)
        {
            validBracketChanged(1);
            changes--;
        }
        validBracketChanged(changes);
        cout <<n;
    }
}
