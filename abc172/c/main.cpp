#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ll N, M, K;
    scanf("%lld %lld %lld", &N, &M, &K);

    vector<ll> A(N);
    vector<ll> B(M);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    for (ll i = 0; i < M; i++)
    {
        scanf("%lld", &B[i]);
    }

    ll i = 0, j = 0;
    ll summin = 0;
    while (true)
    {
        bool isA;
        if (i < N && j < M)
            isA = (A[i] < B[j]);
        else if (i < N)
            isA = true;
        else if (j < M)
            isA = false;
        else
            break;

        if (isA)
        {
            summin += A[i];
            if (summin > K)
                break;
            i++;
        }
        else
        {
            summin += B[j];
            if (summin > K)
                break;
            j++;
        }
    }

    printf("%lld\n", i + j);
}
