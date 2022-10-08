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
    ll S, W;
    scanf("%lld %lld", &S, &W);
    if (S > W)
        printf("safe");
    else
        printf("unsafe");
}
