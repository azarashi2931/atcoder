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
const int mod = 1e9 + 7;

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

vector<vector<ll>> dp(2000, vector<ll>(2000, -1));
ll search(ll rest, ll n)
{
    if (dp[rest][n] != -1)
        return dp[rest][n];

    if (n == 1)
    {
        dp[rest][n] = 1;
        return 1;
    }

    if (n == 2)
    {
        dp[rest][n] = rest + 1;
        return rest + 1;
    }

    ll ans = 0;
    ll left = n / 2;
    for (ll i = 0; i <= rest; i++)
    {
        ans += search(rest - i, left) * search(i, n - left);
        ans %= mod;
    }
    dp[rest][n] = ans;
    return ans;
}

int main()
{
    ll S;
    scanf("%lld", &S);

    ll ans = 0;
    for (ll i = 1; i <= S / 3; i++)
    {
        ll rest = S - i * 3;
        ans += search(rest, i);
        ans %= mod;
    }

    printf("%lld\n", ans);
}
