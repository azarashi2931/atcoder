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

ll abc(ll a)
{
    if (a < 0)
        return -a;
    return a;
}

int main()
{
    ll N;
    scanf("%lld\n", &N);

    string s;
    cin >> s;

    vector<ll> r(N, -1), g(N, -1), b(N, -1);
    vector<ll> indexsum(N, 0);
    ll ri = 0, gi = 0, bi = 0;
    for (ll i = 0; i < N; i++)
    {
        char c = s[i];

        if (c == 'R')
            r[ri++] = i;
        else if (c == 'G')
            g[gi++] = i;
        else
            b[bi++] = i;
    }

    ll x = ri * gi * bi;
    for (ll i = 0; i < N - 2; i++)
    {
        for (ll j = i + 1; j < N - 1; j++)
        {
            ll k = j - i + j;
            if (k < N && s[i] != s[j] && s[j] != s[k] && s[k] != s[i])
                x--;
        }
    }

    printf("%lld", x);
}
