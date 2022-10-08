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
    ll K, A, B;
    scanf("%lld", &K);
    scanf("%lld %lld", &A, &B);

    if (((A / K) + ((A % K == 0) ? 0 : 1)) * K <= B)
        printf("OK");
    else
        printf("NG");
}
