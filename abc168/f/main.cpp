#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <limits>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

struct line
{
    ll a, b;
    bool done;
};

bool isPointOnLine(line l, ll x)
{
    return l.a <= x && l.b >= x;
}

int main()
{
    ll N, M;
    scanf("%lld %lld", &N, &M);
    unordered_map<ll, line> ABC;
    unordered_map<ll, line> DEF;
    vector<ll> A(N), B(N), C(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld %lld %lld", &A[i], &B[i], &C[i]);
        ABC[C[i]] = {A[i], B[i], false};
    }
    vector<ll> D(N), E(N), F(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld %lld %lld", &D[i], &E[i], &F[i]);
        ABC[D[i]] = {E[i], F[i], false};
    }

    while (X)
    {
        /* code */
    }

    ll x = 0x0fffffffffffffff;
    for (auto e : ABC)
    {
        if (isPointOnLine(e.second, 0))
        {
            if (abs(x) > abs(e.first))
            {
                x = e.first;
            }
        }
    }
    ABC[x].done = true;

    ll y = 0x0fffffffffffffff;
    for (auto e : DEF)
    {
        if (isPointOnLine(e.second, x))
        {
            if (abs(y) > abs(e.first))
            {
                y = e.first;
            }
        }
    }
    DEF[x].done = true;
}
