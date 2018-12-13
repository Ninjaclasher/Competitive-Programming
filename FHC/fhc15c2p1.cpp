#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int t, n;
    scanf("%i", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%i", &n);
        deque<int> st (n), tmp, nd;
        for (auto &x : st)
            scanf("%i", &x);
        tmp = st;
        nd.push_front(st.front());
        st.pop_front();
        while (!st.empty())
        {
            if (st.front() == nd.front()-1)
                nd.push_front(st.front()), st.pop_front();
            else if (st.front() == nd.back()+1)
                nd.push_back(st.front()), st.pop_front();
            else if (st.back() == nd.front()-1)
                nd.push_front(st.back()), st.pop_back();
            else if (st.back() == nd.back()+1)
                nd.push_back(st.back()), st.pop_back();
            else
                break;
        }
        if (st.empty())
        {
            printf("Case #%i: yes\n", i);
            continue;            
        }
        st = tmp;
        nd.clear();
        nd.push_front(st.back());
        st.pop_back();
        while (!st.empty())
        {
            if (st.front() == nd.front()-1)
                nd.push_front(st.front()), st.pop_front();
            else if (st.front() == nd.back()+1)
                nd.push_back(st.front()), st.pop_front();
            else if (st.back() == nd.front()-1)
                nd.push_front(st.back()), st.pop_back();
            else if (st.back() == nd.back()+1)
                nd.push_back(st.back()), st.pop_back();
            else
                break;
        }
        printf("Case #%i: %s\n", i, (st.empty() ? "yes" : "no"));
    }
    return 0;
}
