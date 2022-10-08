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
    ll N;
    scanf("%lld", &N);

    map<pair<ll, ll>, bool> points;
    vector<ll> distancesP(N);
    vector<ll> distancesM(N);
    for (ll i = 0; i < N; i++)
    {
        ll x, y;
        scanf("%lld", &x);
        scanf("%lld", &y);
        points[{x, y}] = true;
        distancesP[i] = x + y;
        distancesM[i] = x - y;
    }

    sort(distancesP.begin(), distancesP.end());
    //sort(distancesM.begin(), distancesM.end());
    //ll ans = max(distancesP[N - 1] - distancesP[0], distancesM[N - 1] - distancesM[0]);
    ll ans = distancesP[N - 1] - distancesP[0];
    printf("%lld\n", ans);
}
