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

int main()
{
    ll N;
    scanf("%lld", &N);
    unordered_map<ll, ll> AMap;
    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        ll a;
        scanf("%lld", &a);
        AMap[a]++;
        ans += a;
    }

    ll Q;
    scanf("%lld", &Q);
    for (ll i = 0; i < Q; i++)
    {
        ll b, c;
        scanf("%lld %lld", &b, &c);
        ans -= AMap[b] * b;
        ans += AMap[b] * c;

        AMap[c] += AMap[b];
        AMap[b] = 0;

        printf("%lld\n", ans);
    }
}
