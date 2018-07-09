#include <bits/stdc++.h>

using namespace std;

bool compare (pair<int,int> &a, pair<int,int> &b)
{
    return a.first == b.first ? a.second < b.second : a.first > b.first;
}

int main()
{
    int n, a, b, ip = 0, fri = 0;
    vector<pair<int,int>> people;
    priority_queue<int, vector<int>, greater<int>> buf;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i%i", &a, &b);
        if(!a || !b) 
            fri++;
        else 
            people.push_back(make_pair(a, b));
    }
    sort (people.begin(), people.end(), compare);
    for (int x = 0; x < people.size(); x++)
    {
        buf.push (people[x].second);
        if (people[x].first > people.size() - x - 1 + fri)
            fri++, ip += buf.top(), buf.pop();
    }
    printf("%i", ip);
    return 0;
}
