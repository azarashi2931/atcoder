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
    ll N, x;
    scanf("%lld %lld", &N, &x);

    vector<ll> c(N);
    vector<ll> d(N, 0); //last x
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld", &c[i]);
        d[i] += c[i];
        d[i + 1] += c[i];
    }

    ll dis = 0;
    for (ll i = 0; i < N; i++)
    {
        if (d[i] > x)
        {
            ll diff = d[i] - x;
            d[i] -= diff;
            d[i + 1] -= diff;
            c[i] -= diff;
            dis += diff;
        }
    }
    printf("%lld", dis);
}
