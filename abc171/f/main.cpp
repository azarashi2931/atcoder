#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

ll combination(ll n, ll r)
{
    if (r * 2 > n)
        r = n - r;
    ll dividend = 1;
    ll divisor = 1;
    for (ll i = 1; i <= r; ++i)
    {
        dividend *= (n - i + 1) % mod;
        divisor *= i % mod;
        dividend %= mod;
        divisor %= mod;
    }
    return dividend / divisor;
}

int main()
{
    ll K;
    scanf("%lld", &K);
    string s;
    cin >> s;

    ll ans = 26;
    for (ll i = 1; i < K; i++)
    {
        ans *= 26;
        ans %= mod;
    }
    printf("%lld\n", ans * 26 % mod);

    const ll slen = s.length();

    ll mtemp = 1;
    for (ll i = 0; i < slen; i++)
    {
        mtemp *= 2;
        mtemp %= mod;
    }
    mtemp -= 2;

    ans *= mtemp;
    ans %= mod;

    printf("%lld\n", ans);
}
