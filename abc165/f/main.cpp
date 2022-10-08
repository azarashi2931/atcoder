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

vector<vector<bool>> *routeptr;
vector<ll> *aptr;
ll N;
ll search(ll index)
{
    if (index == N - 1)
        return 1;

    ll current = (*aptr)[index];
    ll m = 0;
    for (ll i = index + 1; i < N; i++)
    {
        if ((*routeptr)[index][i] && (*aptr)[i] > (*aptr)[index])
            m = max(m, search(i));
    }

    return m;
}

int main()
{
    scanf("%lld", &N);
    vector<ll> A(N);
    vector<vector<bool>> route(N, vector<bool>(N, false));
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld", &(A[i]));
    }
    for (ll i = 0; i < N - 1; i++)
    {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        route[u - 1][v - 1] = true;
        route[v - 1][u - 1] = true;
    }
    routeptr = &route;

    vector<ll> dist(N, -1);
    queue<ll> que;
    dist[0] = 0;
    que.push(0);
    while (!que.empty())
    {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        for (int i = 0; i < N; i++)
        {
            if (!route[v][i])
                continue;

            if (dist[i] != -1)
                continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[i] = dist[v] + 1;
            que.push(i);
        }
    }

    printf("%lld", search(0));
}
