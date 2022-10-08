#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

int main()
{
    ll N;
    scanf("%lld", &N);
    vector<ll> a(N);
    vector<ll> sum(N, 0);
    vector<ll> sum1(N, 0);
    scanf("%lld", &a[0]);
    for (ll i = 1; i < N; i++)
    {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
        sum1[i] = sum[i - 1] + a[i];
    }

    ll c1 = 0;
    ll pm = 0;

    for (ll i = 1; i < N; i++)
    {
        ll diff = 0;
        if (sum1[i] + pm == 0)
        {
            if (sum1[i - 1] < 0)
                diff = 1;
            else
                diff = -1;
        }
        else if (signbit(sum1[i] + pm) == signbit(sum1[i - 1]))
        {
            if (sum1[i - 1] < 0)
                diff = abs(sum1[i] + pm) + 1;
            else
                diff = -(abs(sum1[i] + pm) + 1);
        }
        a1[i] += diff;
        pm += diff;
        sum1[i] += pm;
        count += abs(diff);
    }
    ll c2 = 0;
    for (ll i = 1; i < N; i++)
    {
    }
    ll count = 0;
    ll pm = 0;
    for (ll i = 1; i < N; i++)
    {
        ll diff = 0;
        if (sum[i] + pm == 0)
        {
            if (sum[i - 1] < 0)
                diff = 1;
            else
                diff = -1;
        }
        else if (signbit(sum[i] + pm) == signbit(sum[i - 1]))
        {
            if (sum[i - 1] < 0)
                diff = abs(sum[i] + pm) + 1;
            else
                diff = -(abs(sum[i] + pm) + 1);
        }
        a[i] += diff;
        pm += diff;
        sum[i] += pm;
        count += abs(diff);
    }
    printf("%lld", count);
}
