#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <tuple>
#include <cassert>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

#define read_int(X) \
    ll X;           \
    scanf("%lld\n", &X);

#define read_two_int(X, Y) \
    ll X, Y;               \
    scanf("%lld %lld\n", &X, &Y);

#define read_three_int(X, Y, Z) \
    ll X, Y, Z;                 \
    scanf("%lld %lld %lld\n", &X, &Y, &Z);

#define read_four_int(X, Y, Z, W) \
    ll X, Y, Z, W;                \
    scanf("%lld %lld %lld %lld\n", &X, &Y, &Z, &W);

tuple<tuple<ll, ll, ll>, tuple<ll, ll, ll>, tuple<ll, ll, ll>> mul(tuple<tuple<ll, ll, ll>, tuple<ll, ll, ll>, tuple<ll, ll, ll>> lhs,
                                                                   tuple<tuple<ll, ll, ll>, tuple<ll, ll, ll>, tuple<ll, ll, ll>> rhs)
{
    return make_tuple(make_tuple(get<0>(get<0>(lhs)) * get<0>(get<0>(rhs)) + get<0>(get<1>(lhs)) * get<1>(get<0>(rhs)) + get<0>(get<2>(lhs)) * get<2>(get<0>(rhs)),
                                 get<0>(get<0>(lhs)) * get<0>(get<1>(rhs)) + get<0>(get<1>(lhs)) * get<1>(get<1>(rhs)) + get<0>(get<2>(lhs)) * get<2>(get<1>(rhs)),
                                 get<0>(get<0>(lhs)) * get<0>(get<2>(rhs)) + get<0>(get<1>(lhs)) * get<1>(get<2>(rhs)) + get<0>(get<2>(lhs)) * get<2>(get<2>(rhs))),
                      make_tuple(get<1>(get<0>(lhs)) * get<0>(get<0>(rhs)) + get<1>(get<1>(lhs)) * get<1>(get<0>(rhs)) + get<1>(get<2>(lhs)) * get<2>(get<0>(rhs)),
                                 get<1>(get<0>(lhs)) * get<0>(get<1>(rhs)) + get<1>(get<1>(lhs)) * get<1>(get<1>(rhs)) + get<1>(get<2>(lhs)) * get<2>(get<1>(rhs)),
                                 get<1>(get<0>(lhs)) * get<0>(get<2>(rhs)) + get<1>(get<1>(lhs)) * get<1>(get<2>(rhs)) + get<1>(get<2>(lhs)) * get<2>(get<2>(rhs))),
                      make_tuple(get<2>(get<0>(lhs)) * get<0>(get<0>(rhs)) + get<2>(get<1>(lhs)) * get<1>(get<0>(rhs)) + get<2>(get<2>(lhs)) * get<2>(get<0>(rhs)),
                                 get<2>(get<0>(lhs)) * get<0>(get<1>(rhs)) + get<2>(get<1>(lhs)) * get<1>(get<1>(rhs)) + get<2>(get<2>(lhs)) * get<2>(get<1>(rhs)),
                                 get<2>(get<0>(lhs)) * get<0>(get<2>(rhs)) + get<2>(get<1>(lhs)) * get<1>(get<2>(rhs)) + get<2>(get<2>(lhs)) * get<2>(get<2>(rhs))));
}

tuple<ll, ll> mulv(tuple<tuple<ll, ll, ll>, tuple<ll, ll, ll>, tuple<ll, ll, ll>> lhs,
                   tuple<ll, ll> rhs)
{
    return make_tuple(get<0>(get<0>(lhs)) * get<0>(rhs) + get<0>(get<1>(lhs)) * get<1>(rhs) + get<0>(get<2>(lhs)) * 1,
                      get<1>(get<0>(lhs)) * get<0>(rhs) + get<1>(get<1>(lhs)) * get<1>(rhs) + get<1>(get<2>(lhs)) * 1);
}

tuple<tuple<ll, ll, ll>, tuple<ll, ll, ll>, tuple<ll, ll, ll>> op2mat(tuple<ll, ll> op)
{
    //(M, make_tuple(make_tuple(0, 0), make_tuple(0, 0)));
    ll p = get<0>(op);
    ll arg = get<1>(op);
    switch (p)
    {
    case 1:
        return make_tuple(make_tuple(0, 1, 0), make_tuple(-1, 0, 0), make_tuple(0, 0, 1));
    case 2:
        return make_tuple(make_tuple(0, -1, 0), make_tuple(1, 0, 0), make_tuple(0, 0, 1));
    case 3:
        return mul(mul(make_tuple(make_tuple(1, 0, 0), make_tuple(0, 1, 0), make_tuple(-arg, 0, 1)),
                       make_tuple(make_tuple(1, 0, 0), make_tuple(0, -1, 0), make_tuple(0, 0, 1))),
                   make_tuple(make_tuple(1, 0, 0), make_tuple(0, 1, 0), make_tuple(arg, 0, 1)));
    case 4:
        return mul(mul(make_tuple(make_tuple(1, 0, 0), make_tuple(0, 1, 0), make_tuple(0, -arg, 1)),
                       make_tuple(make_tuple(1, 0, 0), make_tuple(0, -1, 0), make_tuple(0, 0, 1))),
                   make_tuple(make_tuple(1, 0, 0), make_tuple(0, 1, 0), make_tuple(0, arg, 1)));
    }
    assert(0);
}

int main()
{
    ll N;
    scanf("%lld", &N);
    vector<ll> X = vector<ll>(N), Y = vector<ll>(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld %lld", &X[i], &Y[i]);
    }

    ll M;
    scanf("%lld", &M);
    vector<tuple<ll, ll>> op = vector<tuple<ll, ll>>(M, make_tuple(0, 0));
    for (ll i = 0; i < M; i++)
    {
        scanf("%lld", &get<0>(op[i]));
        if (get<0>(op[i]) > 2)
            scanf("%lld", &get<1>(op[i]));
    }

    ll Q;
    scanf("%lld", &Q);
    vector<ll> A = vector<ll>(Q), B = vector<ll>(Q);
    for (ll i = 0; i < Q; i++)
    {
        scanf("%lld %lld", &A[i], &B[i]);
    }

    //solve

    vector<tuple<tuple<ll, ll, ll>, tuple<ll, ll, ll>, tuple<ll, ll, ll>>> mixed = vector<tuple<tuple<ll, ll, ll>, tuple<ll, ll, ll>, tuple<ll, ll, ll>>>(M, make_tuple(make_tuple(0, 0, 0), make_tuple(0, 0, 0), make_tuple(0, 0, 0)));
    mixed[0] = op2mat(op[0]);
    for (ll i = 1; i < M; i++)
    {
        mixed[i] = mul(mixed[i - 1], op2mat(op[i]));
    }

    for (ll i = 0; i < Q; i++)
    {
        auto ans = mulv(mixed[A[i]], make_tuple(X[B[i]], Y[B[i]]));
        printf("%lld %lld\n", get<0>(ans), get<1>(ans));
    }
}
