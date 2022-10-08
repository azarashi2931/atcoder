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

int main()
{
    ll N, X;
    scanf("%lld %lld", &N, &X);

    ll sum = 0;
    ll ans = -1;
    for (size_t i = 0; i < N; i++)
    {
        ll V, P;
        scanf("%lld %lld", &V, &P);
        sum += V * P;

        if (sum > X * 100)
        {
            ans = i + 1;
            break;
        }
    }
    printf("%lld\n", ans);
}
