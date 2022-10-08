#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
using ll = long long;

ll s(ll N)
{
    long long int d = 1;
    long long int sum = 0;
    while (N > 0)
    {
        long long int x = (N / d) % 10;
        N -= x * d;
        sum += x;
        d *= 10;
    }

    return sum;
}

int main()
{
    ll K;
    scanf("%lld", &K);

    /*ll x = 1;
    for (ll i = 0; i < K; i++)
    {
        if ((i + 1) % 9 != 0)
            printf("%lld", (i + 1) % 9);
        for (ll j = 0; j < ((i + 1) / 9); j++)
            printf("%d", 9);
        printf("\n");
    }*/

    for (ll i = 0; i < 9; i++)
    {
        printf("%lld\n", i + 1);
    }
    printf("%d\n", 19);

    return 0;
}