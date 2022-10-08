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

    ll s = 0;
    for (ll i = 0; i < M; i++)
    {
        ll A;
        scanf("%lld", &A);
        s += A;
    }

    //if (N - s >= 0)
    printf("%lld", N - s);
    //else
    //    printf("-1");
}
