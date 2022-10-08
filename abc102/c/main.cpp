#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

ll sad(ll b, vector<ll> *B)
{
    ll res = 0;
    for (int i = 0; i < B->size(); i++)
        res += abs((*B)[i] - b);

    return res;
}

int main()
{
    long long int N;
    scanf("%lld", &N);

    ll sum = 0;
    vector<ll> B(N);

    scanf("%lld", &B[0]);
    B[0] -= 1;
    ll maximam = B[0];
    ll minimam = B[0];

    for (ll i = 1; i < N; i++)
    {
        ll A;
        scanf("%lld", &A);
        B[i] = A - (i + 1);
        sum += B[i];
        maximam = max(maximam, B[i]);
        minimam = min(minimam, B[i]);
    }

    sort(B.begin(), B.end());

    ll sad1 = sad(B[N / 2 - 1], &B);
    ll sad2 = sad(B[N / 2], &B);
    ll minsad = min(sad1, sad2);

    printf("%lld", minsad);
}
