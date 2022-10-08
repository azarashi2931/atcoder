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
    ll N;
    scanf("%lld", &N);

    vector<ll> L(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld", &L[i]);
    }

    sort(L.begin(), L.end());

    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        for (ll j = i; j < N; j++)
        {
            for (ll k = j; k < N; k++)
            {
                if (L[i] + L[j] > L[k])
                {
                    if (L[i] != L[j] && L[j] != L[k] && L[k] != L[i])
                        ans++;
                }
                else
                {
                    break;
                }
            }
        }
    }

    printf("%lld\n", ans);
}
