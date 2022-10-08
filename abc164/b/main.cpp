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
    ll A, B, C, D;
    scanf("%lld %lld %lld %lld", &A, &B, &C, &D);

    ll tturn = C / B + (C % B > 0 ? 1 : 0);
    ll aturn = A / D + (A % D > 0 ? 1 : 0);

    if (tturn > aturn)
        printf("No");
    else
        printf("Yes");
}
