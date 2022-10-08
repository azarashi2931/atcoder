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
#include <cmath>
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
    long double X, Y, R;
    scanf("%Lf %Lf %Lf\n", &X, &Y, &R);

    X = fmod(X, 1.0);
    Y = fmod(Y, 1.0);

    ll ans = 0;
    ll xend = floor(X - R);
    ll yend = floor(Y - R);
    for (ll i = 0; i <= R * 2; i++)
    {
        ll a = i + xend;
        a / ;
        ll b1 = floor(sqrt(R * R - (a - R) * (a - R)));
        ll b2 = floor(-sqrt(R * R - (a - R) * (a - R)));
        ans += b1 - b2 - 1;
    }

    printf("%lld\n", ans);
}
