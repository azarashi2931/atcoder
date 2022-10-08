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

    ll i = 0;
    ll sum = 100;
    while (sum < N)
    {
        sum += sum / 100;
        i++;
    }

    printf("%lld", i);
}
