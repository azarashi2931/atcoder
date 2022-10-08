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
    read_two_int(N, M);
    vector<map<ll, ll>> graph(N);

    for (ll i = 0; i < N; i++)
    {
        read_three_int(A, B, C);
        graph[A][B] = C;
    }

    for (ll i = 0; i < N; i++)
    {
        queue<ll> nexts;
        vector<ll> costs(N, -1);
        nexts.push(i);
        while (!nexts.empty())
        {
            auto i = nexts.front();
            nexts.pop();
            ll cost = costs[i];
            for (auto &&city : graph[i])
            {
                if (costs[city.first] == -1 || city.second + cost < costs[city.first])
                {
                    costs[city.first] = cost + city.second;
                    nexts.push(city.first);
                }
            }
        }
        printf("%lld\n", costs[i]);
    }
}
