#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

struct abcdstruct
{
    ll A, B, C, D;
};

struct confabcd
{
    ll i, j;
};

int main()
{
    ll N, M, Q;
    scanf("%lld %lld %lld", &N, &M, &Q);

    vector<abcdstruct> abcdlist(Q);
    for (ll i = 0; i < Q; i++)
    {
        scanf("%lld %lld %lld %lld", &(abcdlist[i].A), &(abcdlist[i].B), &(abcdlist[i].C), &(abcdlist[i].D));
    }

    sort(abcdlist.begin(), abcdlist.end(), [](const abcdstruct &a, const abcdstruct &b) {
        return a.A > b.A;
    });

    //queue<confabcd> conflict(Q);
    vector<vector<ll>> conflictmap(Q, vector<ll>(Q, 0));
    for (ll i = 0; i < Q; i++)
    {
        for (ll j = i + 1; j < Q; j++)
            if (abcdlist[j].B <= abcdlist[i].B && abcdlist[j].C > abcdlist[i].C)
            {
                conflictmap[i][j] += abcdlist[j].D;
                conflictmap[j][i] += abcdlist[i].D;
            }
    }
    for (ll i = 0; i < Q; i++)
    {
        ll sum = 0;
        for (ll j = 0; j < Q; j++)
            sum += conflictmap[i][j];
        if (sum >= abcdlist[i].D)
        {
            abcdlist[i].D = 0;
            for (ll j = 0; j < Q; j++)
                conflictmap[i][j] = 0;
        }
    }
    ll sum = 0;
    for (ll i = 0; i < Q; i++)
        sum += abcdlist[i].D;
    printf("%lld", sum);
}
