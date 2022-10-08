#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

typedef long long ll;

//解説AC

ll getDiff(ll N, ll i, ll j, ll k, vector<ll> *sum)
{
    ll p = (*sum)[i];
    ll q = (*sum)[j] - (*sum)[i];
    ll r = (*sum)[k] - (*sum)[j];
    ll s = (*sum)[N - 1] - (*sum)[k];

    ll minimam = min(min(p, q), min(r, s));
    ll maximam = max(max(p, q), max(r, s));

    return maximam - minimam;
}

int main()
{
    ll N;
    scanf("%lld", &N);

    vector<ll> sum(N);
    scanf("%lld", &sum[0]);
    for (ll i = 1; i < N; i++)
    {
        ll A;
        scanf("%lld", &A);
        sum[i] = sum[i - 1] + A;
    }

    ll res = 2 * pow(10, 14) * 10;
    ll all = sum[N - 1];
    for (ll j = 1; j < N - 2; j++)
    {
        ll pq = sum[j];
        ll rs = all - pq;

        ll upper = 0, lower = j;
        const ll target = pq / 2;
        while (true)
        {
            ll m = (upper + lower) / 2;
            if (sum[m] > target)
                lower = m;
            else if (sum[m] < target)
                upper = m;
            else
                break;
        }
        ll i = upper;

        for (ll k = 0; k < N - 1; k++)
        {
        }
    }
    for (ll i = 0; i < N - 3; i++)
    {
        ll p = sum[i];
        ll qrs = all - p;
        ll idealDifx3 = abs(qrs - p * 3);
        if (idealDifx3 >= res * 3)
            continue;

        for (ll j = i + 1; j < N - 2; j++)
        {
            ll pq = sum[j];
            ll q = pq - p;
            ll rs = all - pq;
            ll difx2 = max(rs, max(p * 2, q * 2)) - min(rs, max(p * 2, q * 2));
            if (difx2 >= res * 2)
                continue;

            for (ll k = j + 1; k < N - 1; k++)
            {
                res = min(res, getDiff(N, i, j, k, &sum));
            }
        }
    }

    printf("%lld", res);
}
