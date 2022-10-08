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

ll char2int(char c)
{
    return c - '0';
}

vector<ll> mem10(100, -1);
ll repeatSquaring10(ll P)
{
    //if (mem10[P] != -1)
    //    return mem10[P];
    ll ans;
    if (P == 0)
        ans = 1;
    else if (P % 2 == 0)
    {
        ll t = repeatSquaring10(P / 2);
        ans = t * t;
    }
    else
        ans = 10 * repeatSquaring10(P - 1);
    //mem10[P] = ans;
    return ans;
}

int main()
{
    string s;
    cin >> s;

    vector<ll> sum(s.size(), 0);
    sum[0] = char2int(s[0]);
    for (ll i = 1; i < s.size(); i++)
        sum[i] += sum[i - 1] + char2int(s[i]);

    if (s.size() < 4)
    {
        printf("0");
        return 0;
    }

    ll ans = 0;
    //vector<vector<ll>> dp(s.size(), vector<ll>(s.size(), 0));
    for (ll i = 0; i < s.size(); i++)
    {
        for (ll j = 4; j <= s.size() - i; j++)
        {
            //printf("%lld\n", num);
            if ((sum[i + j - 1] - (i > 0 ? sum[i - 1] : 0)) % 3 == 0)
            {
                ll num = 0;
                for (ll k = 0; k < j; k++)
                    num += char2int(s[i + k]) * repeatSquaring10(j - k - 1);
                if (num % 673 == 0)
                {
                    ans++;
                }
            }
        }
    }

    printf("%lld", ans);
}
