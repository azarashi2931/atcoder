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

struct axpair
{
    ll a;
    ll x;
};

int main()
{
    ll N;
    scanf("%lld", &N);

    vector<axpair> A(N);
    for (ll i = 0; i < N; i++)
    {
        ll Ai;
        scanf("%lld", &Ai);
        A[i].x = i;
        A[i].a = Ai;
    }

    sort(A.begin(), A.end(), [](auto const &lhs, auto const &rhs) {
        return lhs.a > rhs.a;
    });

    ll ans = 0;
    ll left = 0, right = 0;
    vector<vector<ll>> dp(N, vector<ll>(N, -1));
    for (ll i = 0; i < N; i++)
    {
        ll y;
        const ll yl = left, yr = N - 1 - right;
        if (abs(A[i].x - yl) > abs(A[i].x - yr))
        {
            y = yl;
            left++;
        }
        else
        {
            y = yr;
            right++;
        }
        printf("%lld %lld\n", abs(A[i].x - y), A[i].a);
        ans += abs(A[i].x - y) * A[i].a;
    }

    printf("%lld\n", ans);
}
