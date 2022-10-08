#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ll N, M;
    scanf("%lld %lld", &N, &M);

    vector<ll> H(N);
    for (ll i = 0; i < N; i++)
        scanf("%lld", &(H[i]));

    vector<vector<ll>> pass(N, vector<ll>());
    for (ll i = 0; i < M; i++)
    {
        ll A, B;
        scanf("%lld %lld", &A, &B);
        pass[A - 1].push_back(B - 1);
        pass[B - 1].push_back(A - 1);
    }

    vector<ll> pm(N, -1);
    for (ll i = 0; i < N; i++)
    {
        if (pm[i] != -1)
            continue;

        bool res = true;
        for (auto to : pass[i])
        {
            if (H[to] >= H[i])
            {
                res = false;
            }
            if (H[to] <= H[i])
            {
                pm[to] = false;
            }
        }

        pm[i] = res;
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        if (pm[i] == 1)
            ans++;
    }
    printf("%lld\n", ans);
}
