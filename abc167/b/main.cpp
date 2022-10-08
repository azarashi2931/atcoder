#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <limits>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ll A, B, C, K;
    scanf("%lld %lld %lld %lld", &A, &B, &C, &K);

    if (A >= K)
        printf("%lld", K);
    else if (A + B >= K)
        printf("%lld", A);
    else
        printf("%lld", A - (K - A - B));
}
