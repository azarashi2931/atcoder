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
    ll N, K;
    scanf("%lld %lld", &N, &K);
    vector<ll> A(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
        A[i] %= mod;
    }

    sort(A.begin(), A.end(), [](const auto &lh, const auto &rh) { return abs(lh) > abs(rh); });

    for (ll i = 0; i < K; i++)
    {
        printf("%lld\n", A[i]);
    }

    ll ans = 1;
    ll i;
    for (i = 0; i < K - 1; i++)
    {
        ans *= A[i];
        A[i] %= mod;
    }
    if (ans < 0)
    {
        for (; i < N; i++)
        {
            if (A[i] < 0)
                break;
        }
        if (i < N)
        {
            ans *= A[i];
            A[i] %= mod;
        }
        else
        {
        }
    }

    printf("%lld\n", ans);
}
