#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

#define ll long long

vector<vector<ll>> gcdMemo(200, vector<ll>(200, -1));

ll getGcd(ll x, ll y)
{
    if (gcdMemo[x - 1][y - 1] != -1)
        return gcdMemo[x - 1][y - 1];

    ll result;
    if (x % y == 0)
        result = y;
    else
        result = getGcd(y, x % y);

    gcdMemo[x - 1][y - 1] = result;
    return result;
}

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f)
{
    if (rest == 0)
    {
        f(indexes);
    }
    else
    {
        if (s < 0)
            return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

void foreach_comb(int n, int k, std::function<void(int *)> f)
{
    int indexes[k];
    recursive_comb(indexes, n - 1, k, f);
}

int main()
{
    ll N, K;
    scanf("%lld %lld", &N, &K);

    ll sum = 0;
    for (ll i = 1; i <= K; i++)
    {
        foreach_comb(K, i, [N, K, &sum](int *indexes) {
            ll i = indexes[0] + 1;
            ll j = indexes[1] + 1;
            ll k = indexes[2] + 1;
            //ll ij = getGcd(i, j);
            //ll ijk = getGcd(ij, k);
            /*if (i == j && j == k)
                sum += ijk;
            else if (i == j || j == k || i == k)
                sum += (pow(2, N) - 2) * ijk;
            else
                sum += (pow(3, N) - 3) * ijk;*/
        });
    }

    printf("%lld", sum);
}
