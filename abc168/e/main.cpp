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
    ll N;
    scanf("%lld", &N);

    vector<ll> A(N), B(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld %lld", &A[i], &B[i]);
        B[i] *= -1;
    }

    ll d = A[i] * A[j] + B[i] * B[j];
    if (d == 0)
        if (d * d == abs((A[i] * A[i] + B[i] * B[i]) * (A[j] * A[j] + B[j] * B[j]))) //並行
        {
        }

    printf("%lld", x);
}
