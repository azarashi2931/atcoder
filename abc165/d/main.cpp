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
    ll A, B, N;
    scanf("%lld %lld %lld", &A, &B, &N);

    ll m = min(B - 1, N) * A / B;

    printf("%lld", m);
}
