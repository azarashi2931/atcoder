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

    vector<ll> A(N);
    ll ans = 0;
    scanf("%lld", &A[0]);
    for (ll i = 1; i < N; i++)
    {
        scanf("%lld", &A[i]);
        ll dif = max(A[i - 1] - A[i], (ll)0);
        A[i] += dif;
        ans += dif;
    }

    printf("%lld\n", ans);
}
