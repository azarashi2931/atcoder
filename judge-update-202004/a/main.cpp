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
    ll S, L, R;
    scanf("%lld %lld %lld", &S, &L, &R);

    ll res;
    if (S < L)
        res = L;
    else if (S > R)
        res = R;
    else
        res = S;
    printf("%lld", res);
}
