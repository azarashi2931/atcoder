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
    unordered_map<ll, ll> A;
    scanf("%lld", &N);

    for (ll i = 1; i <= N; i++)
    {
        ll cnt = 0, target = i;
        for (ll j = 1; j < target; j++)
        {
            if (target % j == 0)
                cnt++;
        }
        if (cnt == 2)
            A[i] = cnt;
    }

    string s;
    cin >> s;

    ll ans = 0;
    printf("%lld\n", ans);
}
