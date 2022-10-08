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
    vector<ll> p(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld", &p[i]);
    }

    sort(p.begin(), p.end());

    ll ans = 0;
    for (ll i = 0; i < K; i++)
    {
        ans += p[i];
    }

    printf("%lld\n", ans);
}
