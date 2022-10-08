#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ll X, K, D;
    scanf("%lld", &X);
    scanf("%lld", &K);
    scanf("%lld", &D);

    ll progress = min(abs(X) / D, K);
    ll ans = abs(X) - D * progress;
    K -= progress;
    if (K % 2 == 1)
    {
        ans = abs(ans - D);
    }

    printf("%lld\n", ans);
}
