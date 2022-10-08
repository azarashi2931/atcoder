#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
using namespace std;

#define ll long long

vector<vector<ll>> gcdMemo(200, vector<ll>(200, -1));

ll getGcd(ll x, ll y)
{
    if (gcdMemo[x - 1][y - 1] != -1)
        return gcdMemo[x - 1][y - 1];

    ll result;
    if (x % y == 0)
        result = y;
    else
        result = getGcd(y, x % y);

    gcdMemo[x - 1][y - 1] = result;
    return result;
}

int main()
{
    ll N;
    scanf("%lld", &N);

    ll sum = 0;
    for (ll i = 1; i <= N; i++)
        for (ll j = 1; j <= N; j++)
            for (ll k = 1; k <= N; k++)
            {
                ll ij = getGcd(i, j);
                ll ijk = getGcd(k, ij);
                sum += ijk;
            }

    printf("%lld", sum);
}
