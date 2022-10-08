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
#include <cmath>
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

vector<ll> divisors(ll N)
{
    vector<ll> res;
    for (ll i = 1; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            res.push_back(i);
            if (N / i != i)
                res.push_back(N / i);
        }
    }

    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ll N;
    scanf("%lld", &N);

    // (2k + n - 1)n/2 = N
    // 2N = (2k + n - 1)n
    // 2N/n = 2k + n - 1
    // k = N/n - n/2 + 1/2

    ll ans = 0;
    vector<ll> d = divisors(2 * N);
    for (ll i = 0; i < d.size(); i++)
    {
        if (2 * N / d[i] % 2 != d[i] % 2)
        {
            ans++;
        }
    }

    printf("%lld\n", ans);
}
