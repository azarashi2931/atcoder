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
    ll N, K;
    scanf("%lld %lld", &N, &K);

    vector<bool> sunuke(N, false);
    for (ll i = 0; i < K; i++)
    {
        ll d;
        scanf("%lld", &d);
        for (ll j = 0; j < d; j++)
        {
            ll a;
            scanf("%lld", &a);
            sunuke[a - 1] = true;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        if (!sunuke[i])
        {
            ans++;
        }
    }
    printf("%lld\n", ans);
}
