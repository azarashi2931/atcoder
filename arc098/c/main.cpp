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

    string s;
    cin >> s;

    vector<ll> w(N), e(N);
    if (s[0] == 'W')
    {
        w[0] = 1;
        e[0] = 0;
    }
    else
    {
        w[0] = 0;
        e[0] = 1;
    }

    for (ll i = 1; i < N; i++)
    {
        w[i] = w[i - 1];
        e[i] = e[i - 1];
        if (s[i] == 'W')
            w[i]++;
        else
            e[i]++;
    }

    ll minc = e[N - 1] - e[0];
    for (ll i = 1; i < N; i++)
    {
        minc = min(w[i - 1] + e[N - 1] - e[i], minc);
    }

    printf("%lld", minc);
}
