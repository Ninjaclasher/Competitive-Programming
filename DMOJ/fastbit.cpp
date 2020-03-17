/* Fake Solution:
 * `int setbits (unsigned long long a){}`
 */

#include <bits/stdc++.h>

using namespace std;

int setbits (unsigned long long a)
{
    bitset<64> aa (a);
    return aa.count();
}
