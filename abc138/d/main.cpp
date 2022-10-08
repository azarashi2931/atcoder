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

void update_node(vector<vector<ll>> *paths, unordered_map<ll, ll> *steps, vector<ll> *nodes, ll previous, ll node, ll current)
{
    current += (*steps)[node];
    (*nodes)[node] = current;
    for (auto &&i : (*paths)[node])
    {
        if (i == previous)
            continue;

        update_node(paths, steps, nodes, node, i, current);
    }
}

int main()
{
    ll N, Q;
    scanf("%lld", &N);
    scanf("%lld", &Q);

    vector<vector<ll>> path(N, vector<ll>());
    for (ll i = 1; i < N; i++)
    {
        ll a, b;
        scanf("%lld", &a);
        scanf("%lld", &b);
        a--;
        b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    unordered_map<ll, ll> steps(0);
    for (ll i = 0; i < Q; i++)
    {
        ll p, x;
        scanf("%lld", &p);
        scanf("%lld", &x);
        p--;
        steps[p] += x;
    }

    vector<ll> nodes(N);
    update_node(&path, &steps, &nodes, -1, 0, 0);

    for (ll i = 0; i < N - 1; i++)
    {
        printf("%lld ", nodes[i]);
    }
    printf("%lld\n", nodes[N - 1]);
}
