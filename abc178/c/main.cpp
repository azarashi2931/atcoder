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

int main()
{
    ll N;
    scanf("%lld", &N);

    ll ans = 1;
    ll noX = 1;
    ll noXY = 1;
    for (ll i = 0; i < N; i++)
    {
        ans *= 10;
        ans %= mod;

        noX *= 9;
        noX %= mod;

        noXY *= 8;
        noXY %= mod;
    }
    ans = (ans - (noX * 2 % mod)) % mod + noXY;
    //ans = (ans + noXY) % mod - (noX * 2 % mod);
    ans %= mod;

    printf("%lld\n", ans);
}
