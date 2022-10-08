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

ll sigl(ll box, ll N)
{
    ll moverange = N - box + 1;
    return moverange * (moverange + 1) * (N + 1) / 2 - moverange * (moverange + 1) * (moverange * 2 + 1) / 6;
}

int main()
{
    read_int(T);
    vector<ll> data(T);
    for (ll i = 0; i < T; i++)
    {
        read_three_int(N, A, B);
        ll ans = 0;
        if (N < A + B)
            ans = 0;
        {
            ll a = N - A + 1;
            ll b = N - B + 1;

            a %= mod;
            b %= mod;

            ans = a * a % mod;
            ans *= b * b % mod;
            ans %= mod;

            //ll k = mergedbox(i) * mergedbox(j) * (N - mergedbox(i) + 1) * (N - mergedbox(j) + 1);
            //ll k = mergedbox(j) * (N - mergedbox(j) + 1) * mergedbox(i) * (N - mergedbox(i) + 1);
            //ll l = boxX * (N - boxX + 1);
            //ll l = mergedbox(i) * (N + 1) - mergedbox(i) * mergedbox(i);
            //ll sigl = mergedbox * (mergedbox + 1) * (N + 1) / 2 - mergedbox * (mergedbox + 1) * (mergedbox * 2 + 1) / 6;
            ll x = sigl(A + B - 1, N);
            ll y = sigl(max(A, B) - 1, N);
            ll temp = (sigl(A + B - 1, N) - sigl(max(A, B) - 1, N)) * (sigl(A + B - 1, N) - sigl(max(A, B) - 1, N));
            temp %= mod;

            ans -= temp;
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
}
