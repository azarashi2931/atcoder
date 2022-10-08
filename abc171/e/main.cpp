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
    vector<ll> A(N);
    ll all = 0;
    for (ll i = 0; i < N; i++)
    {
        ll a;
        scanf("%lld", &a);
        A[i] = a;
        all ^= a;
    }

    for (ll i = 0; i < N; i++)
    {
        printf("%lld ", all ^ A[i]);
    }
}
