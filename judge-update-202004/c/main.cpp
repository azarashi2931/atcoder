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

vector<ll> A(3);

ll func(ll i, ll j)
{
    ll res = 0;
    if (i < 3 && A[i] >= j)
        res += func(i + 1, j);
    if (A[i - 1] > j)
        res += func(i, j + 1);
    if (res == 0)
        res = 1;

    return res;
}

int main()
{
    scanf("%lld %lld %lld", &A[0], &A[1], &A[2]);

    ll N = A[0] + A[1] + A[2];

    ll res = func(1, 1);
    printf("%lld", res);
}
