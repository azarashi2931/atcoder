#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ll N;
    scanf("%lld\n", &N);

    vector<ll> A(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }

    sort(A.begin(), A.end());

    ll ans = 0;
    priority_queue<ll> circle;
    for (ll i = N - 1; i >= 0; i--)
    {
        if (i != N - 1)
        {
            ans += circle.top();
            circle.pop();
        }

        circle.push(A[i]);
        if (i != N - 1)
        {
            circle.push(A[i]);
        }
    }

    printf("%lld\n", ans);
}
