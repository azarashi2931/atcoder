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
    vector<ll> l(N, -1), r(N, -1);
    for (ll i = 0; i < N; i++)
        scanf("%lld %lld", &l[i], &r[i]);

    for (ll i = M; i > 0; i--)
    {
        ll ans = 0;
        for (ll j = 0; j < N; j++)
            if (l[j] % i == 0 || (l[j] / i + 1) * i <= r[j])
                ans++;

        printf("%lld\n", ans);
    }
}
