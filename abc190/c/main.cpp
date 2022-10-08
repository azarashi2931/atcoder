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
    ll N, M;
    scanf("%lld", &N);
    scanf("%lld", &M);

    vector<ll> A(M);
    vector<ll> B(M);
    for (ll i = 0; i < M; i++)
    {
        scanf("%lld", &A[i]);
        scanf("%lld", &B[i]);
    }

    ll K;
    scanf("%lld", &K);

    vector<ll> C(K);
    vector<ll> D(K);
    for (ll i = 0; i < K; i++)
    {
        scanf("%lld", &C[i]);
        scanf("%lld", &D[i]);
    }

    ll ans = 0;
    for (ll i = 0; i < (2 << K) - 1; i++)
    {
        vector<bool> dish(N, false);
        for (ll j = 0; j < K; j++)
        {
            if ((i >> j) % 2)
                dish[C[j] - 1] = true;
            else
                dish[D[j] - 1] = true;
        }

        ll currentans = 0;
        for (ll j = 0; j < M; j++)
        {
            currentans += dish[A[j] - 1] && dish[B[j] - 1];
        }
        ans = max(ans, currentans);
    }

    printf("%lld\n", ans);
}
