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
    ll N;
    scanf("%lld", &N);

    vector<string> S = vector<string>(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    vector<ll> ans = vector<ll>(N + 1);
    ans[0] = 1;
    ll pow2 = 2;
    for (ll i = 0; i < N; i++)
    {
        ans[i + 1] = ans[i];
        if (S[i] == "OR")
            ans[i + 1] += pow2;
        pow2 *= 2;
    }

    printf("%lld\n", ans[N]);
}
