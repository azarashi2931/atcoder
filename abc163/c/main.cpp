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
    ll N;
    scanf("%lld", &N);

    vector<ll> ans(N, 0);
    for (ll i = 2; i <= N; i++)
    {
        ll A;
        scanf("%lld", &A);
        ans[A - 1]++;
    }

    for (ll i = 0; i < N; i++)
        printf("%lld\n", ans[i]);
}
