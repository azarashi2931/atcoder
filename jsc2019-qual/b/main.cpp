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

int main()
{
    ll N, K;
    scanf("%lld %lld", &N, &K);
    K %= 1000000007;

    vector<ll> A(N);
    for (ll i = 0; i < N; i++)
        scanf("%lld", &A[i]);

    ll cnt = 0;
    ll fkm1 = 1;
    for (ll i = 1; i <= K - 1; i++)
        fkm1 = fkm1 * i;
    ll fk = K * fkm1;

    for (ll i = 0; i < N - 1; i++)
    {
        ll left = 0, right = 0;
        for (ll j = 0; j < i; j++)
            if (A[i] > A[j])
                left++;
        for (ll j = i + 1; j < N; j++)
            if (A[i] > A[j])
                right++;

        cnt += fkm1 * left % 1000000007;
        cnt += (fk + K - 1) * right % 1000000007;
    }
    printf("%lld", cnt % 1000000007);
}
