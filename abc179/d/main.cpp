#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <tuple>
#include <cassert>
using namespace std;
using ll = long long;
const int mod = 998244353;

#define read_int(X) \
    ll X;           \
    scanf("%lld\n", &X);

#define read_two_int(X, Y) \
    ll X, Y;               \
    scanf("%lld %lld\n", &X, &Y);

#define read_three_int(X, Y, Z) \
    ll X, Y, Z;                 \
    scanf("%lld %lld %lld\n", &X, &Y, &Z);

#define read_four_int(X, Y, Z, W) \
    ll X, Y, Z, W;                \
    scanf("%lld %lld %lld %lld\n", &X, &Y, &Z, &W);

int main()
{
    read_two_int(N, K);
    vector<pair<ll, ll>> lr(K);
    for (ll i = 0; i < K; i++)
    {
        scanf("%lld", &(lr[i].first));
        scanf("%lld", &(lr[i].second));
    }

    vector<ll> dp(N, 0);
    dp[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        ll sum = 0;
        for (ll k = 0; k < K; k++)
        {
            ll diff = 0;
            if (i - lr[k].first >= 0)
                diff = dp[i - lr[k].first];
            if (i - lr[k].second - 1 >= 0)
                diff -= dp[i - lr[k].second - 1];
            sum += diff;
            sum %= mod;
        }

        dp[i] = sum + dp[i - 1];
    }
    ll ans = dp[N - 1] - dp[N - 2];

    printf("%lld\n", ans);
}
