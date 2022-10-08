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

vector<set<ll>> graph;
vector<bool> reachable;
void mark_reachable(ll current)
{
    reachable[current] = true;
    for (const auto x : graph[current])
        if (!reachable[x])
            mark_reachable(x);
}

struct movable_grid
{
    ll cost;
    pair<ll, ll> relative;
};

vector<vector<ll>> bfs_grid_shotest_path(vector<set<ll>> graph, ll start)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> nexts;
    nexts.push({start, 0});
    vector<ll> mincostmap(graph.size(), __LONG_LONG_MAX__);
    while (!nexts.empty())
    {
        auto current = nexts.top();
        nexts.pop();
        for (auto next : graph[current.first])
        {
            ll cost = current.second + 1;
            if (mincostmap[next] > cost)
            {
                mincostmap[next] = cost;
                nexts.push({next, cost});
            }
        }
    }

    return mincostmap;
}

int main()
{
    ll N, M;
    scanf("%lld", &N);
    scanf("%lld", &M);

    graph = vector<set<ll>>(N, set<ll>());
    vector<ll> A(M);
    vector<ll> B(M);
    for (ll i = 0; i < M; i++)
    {
        scanf("%lld", &A[i]);
        scanf("%lld", &B[i]);
        graph[A[i]].insert(B[i]);
        graph[B[i]].insert(A[i]);
    }

    ll K;
    scanf("%lld", &K);
    vector<ll> C(K);
    for (ll i = 0; i < K; i++)
    {
        scanf("%lld", &C[i]);
    }

    bool ans = true;
    reachable = vector<bool>(N, false);
    mark_reachable(C[0]);
    for (auto x : C)
        ans = ans && reachable[x];

    printf("%lld\n", ans);
}
