#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long

int main()
{
    ll N;
    scanf("%lld", &N);
    vector<ll> BX(N, LLONG_MAX), RX(N, LLONG_MAX);
    ll rcount = 0, bcount = 0;
    for (ll i = 0; i < N; i++)
    {
        ll x;
        char c;
        scanf("%lld %c", &x, &c);

        if (c == 'B')
        {
            BX[i] = x;
            bcount++;
        }
        else
        {
            RX[i] = x;
            rcount++;
        }
    }

    sort(BX.begin(), BX.end());
    sort(RX.begin(), RX.end());

    for (ll i = 0; i < rcount; i++)
    {
        printf("%lld\n", RX[i]);
    }

    for (ll i = 0; i < bcount; i++)
    {
        printf("%lld\n", BX[i]);
    }
}
