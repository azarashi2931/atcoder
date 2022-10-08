#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    string s;
    cin >> s;

    ll r = 0;
    vector<ll> ans(s.length(), 0);
    for (ll i = 0; i < s.length(); i++)
    {
        r++;
        if (s[i] == 'R' && s[i + 1] == 'L')
        {
            ll l = 0;
            for (ll j = i + 1; s[j] == 'L'; j++)
                l++;

            ll f = (r + l) / 2,
               b = (r + l) / 2;
            if (l % 2 == 1 && r % 2 == 0)
                b++;
            if (l % 2 == 0 && r % 2 == 1)
                f++;

            ans[i] = f;
            ans[i + 1] = b;
            for (ll j = 1; j < l; j++)
                ans[i + 1 + j] = 0;
            i += l;
            r = 0;
        }
    }

    for (ll i = 0; i < s.length(); i++)
        printf("%lld ", ans[i]);
}
