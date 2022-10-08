#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    long long int N;
    scanf("%lld", &N);

    long long maximam;
    scanf("%lld", &maximam);
    long long minimam = maximam;

    for (long long i = 1; i < N; i++)
    {
        long long A;
        scanf("%lld", &A);
        maximam = max(maximam, A);
        minimam = min(minimam, A);
    }

    printf("%lld", maximam - minimam);
}
