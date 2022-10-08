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

    ll ans = 0;
    for (ll i = K; i <= N + 1; i++)
    {
        ll minS = i * (i - 1) / 2;
        ll maxS = i * (N + N - i + 1) / 2;
        ans += maxS - minS + 1;
    }

    printf("%lld", ans % 1000000007);
}
