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
    ll N, M;
    scanf("%lld %lld", &N, &M);

    if (N % 2 == 0)
        for (ll i = 0; i < M; i++)
            printf("%lld %lld\n", N / 2 - i, N / 2 + i + 1);
    else
        for (ll i = 0; i < M; i++)
            printf("%lld %lld\n", N / 2 - i, N / 2 + i + 1);
}
