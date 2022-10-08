#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

#define ll long long

struct linedata
{
    bool exists;
    ll coins;
    ll minites;
};

int main()
{
    ll N, M, S;
    scanf("%lld %lld %lld", &N, &M, &S);

    vector<vector<linedata>> railway(N, vector<linedata>(N, {false, 0, 0}));
    for (ll i = 0; i < M; i++)
    {
        ll U, V;
        linedata d;
        scanf("%lld %lld %lld %lld", &U, &V, &(d.coins), &(d.minites));
        d.exists = true;

        railway[U - 1][V - 1] = d;
        railway[V - 1][U - 1] = d;
    }
    vector<ll> exchanges(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld %lld", &exchanges[i], &exchanges[i]);
    }

    vector<ll> minimumroute(N, LLONG_MAX);
    minimumroute[0] = 0;
    vector<ll> coincount(N, 0);
    priority_queue<ll> que;
    que.push(0);
    while (!que.empty())
    {
        ll station = que.top();
        que.pop();

        for (ll i = 1; i < N; i++)
            if (railway[station][i].exists)
            {
                if (minimumroute[station] + railway[station][i].minites > minimumroute[i])
                    break;
            }
    }

    //printf("%lld", x);
}
