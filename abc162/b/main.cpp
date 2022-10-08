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
    ll N;
    scanf("%lld", &N);

    ll sum = 0;
    for (ll i = 1; i <= N; i++)
    {
        if (i % 3 != 0 && i % 5 != 0)
            sum += i;
    }

    printf("%lld", sum);
}
