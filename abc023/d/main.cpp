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
#include <set>
#include <tuple>
#include <cassert>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ll N;
    scanf("%lld", &N);

    vector<ll> H(N);
    vector<ll> S(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld", &H[i]);
        scanf("%lld", &S[i]);
    }

    for (ll i = 0; i < N; i++)
    {
    }

    ll ans = 0;
    printf("%lld\n", ans);
}
