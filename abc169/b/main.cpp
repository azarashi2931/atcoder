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
const ll lim = 1e18;

int main()
{
    ll N, res;
    scanf("%lld", &N);
    scanf("%lld", &res);
    for (ll i = 1; i < N; i++)
    {
        ll A, pre = res;
        scanf("%lld", &A);
        if (res != -1 || A == 0)
            res *= A;
        if ((pre != 0 && A > 0xffffffffffffffff / pre) || res > lim)
        {
            res = -1;
        }
        if (res == 0)
            break;
    }

    printf("%lld\n", res);
}
