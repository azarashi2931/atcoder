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
#include <cmath>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main()
{
    ll N, M, K;
    scanf("%lld %lld %lld", &N, &M, &K);

    vector<ll> dp(N, vector<ll>(K, 0));
    dp[1][1] = M;
    ll outpattern = 0;
    for (ll i = 1; i < N; i++)
    {
        dp[i] = (dp[i - 1] - dp[i - 2]) * M % mod;
    }

    printf("%lld", dp[N - 1]);
}
