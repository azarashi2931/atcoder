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
    ll N, M;
    scanf("%lld %lld", &N, &M);

    vector<vector<ll>> route(N);
    for (ll i = 0; i < M; i++)
    {
        ll A, B;
        scanf("%lld %lld", &A, &B);
        route[A - 1].push_back(B - 1);
        route[B - 1].push_back(A - 1);
    }

    vector<ll> dis(N, 0x0fffffffffffffff);
    dis[0] = 0;
    vector<ll> to(N, 0);
    queue<ll> sq;
    sq.push(0);

    while (!sq.empty())
    {
        ll current = sq.front();
        sq.pop();
        for (const auto dest : route[current])
        {
            if (dis[dest] > dis[current] + 1)
            {
                dis[dest] = dis[current] + 1;
                to[dest] = current;
                sq.push(dest);
            }
        }
    }

    printf("Yes\n");
    for (ll i = 1; i < N; i++)
    {
        printf("%lld\n", to[i] + 1);
    }
}
