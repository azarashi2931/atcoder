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
const int mod = 1e9 + 7;

int main()
{
    ll N, M, X;
    scanf("%lld %lld %lld", &N, &M, &X);
    vector<ll> C(N);
    vector<vector<ll>> A(N, vector<ll>(M));
    for (ll i = 0; i < N; i++)
    {
        cin >> C[i];
        for (ll j = 0; j < M; j++)
            cin >> A[i][j];
    }

    vector<ll> skill(M, 0);
    ll count = pow(2, N);
    ll mincost = 10000000;
    bool ans = false;
    for (ll i = 0; i < count; i++)
    {
        ll cost = 0;
        for (ll j = 0; j < N; j++)
        {
            if ((i >> j) & 1)
            {
                for (ll k = 0; k < M; k++)
                {
                    skill[k] += A[j][k];
                }
                cost += C[j];
            }
        }

        bool res = true;
        for (ll k = 0; k < M; k++)
        {
            if (skill[k] < X)
            {
                res = false;
                break;
            }
        }
        for (ll k = 0; k < M; k++)
            skill[k] = 0;

        if (res)
            mincost = min(mincost, cost);
        ans |= res;
    }

    if (ans)
        printf("%lld", mincost);
    else
        printf("-1");
}
