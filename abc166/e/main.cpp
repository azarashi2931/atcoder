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

#define ll long long

int main()
{
    ll N;
    scanf("%lld", &N);

    vector<ll> sum(N);
    unordered_map<ll, ll> backmap;
    for (ll i = 0; i < N; i++)
    {
        ll A;
        scanf("%lld", &A);
        if (i - A > 0)
            backmap[i - A]++;
        sum[i] = i + A;
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++)
        ans += backmap[sum[i]];
    printf("%lld\n", ans);
}
