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

int main()
{
    ll N, K;
    scanf("%lld %lld", &N, &K);
    vector<ll> A(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i]--;
    }

    ll id = 0;
    vector<ll> check(N, -1);
    ll loopid, loopcount;
    for (ll i = 0; i < N; i++)
    {
        if (check[id] != -1)
        {
            loopid = id;
            loopcount = i - check[id];
            break;
        }

        check[id] = i;
        id = A[id];
    }

    id = 0;
    for (ll i = K; i >= 0; i--)
    {
        if (id == loopid)
        {
            i %= loopcount;
        }

        if (i != 0)
            id = A[id];
    }

    printf("%lld", id + 1);
}
