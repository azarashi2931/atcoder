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

template <int N>
struct Pow5
{
    ll ary[N];
    constexpr Pow5() : ary()
    {
        for (ll i = 0; i < N; i++)
        {
            ary[i] = i * i * i * i * i;
        }
    }
};

int main()
{
    ll X;
    scanf("%lld", &X);

    constexpr auto pow5 = Pow5<1000>();
    for (ll a = 1; a < 1000; a++)
    {
        for (ll b = -1000; b < 1000; b++)
        {
            ll ap5 = a < 0 ? -pow5.ary[-a] : pow5.ary[a];
            ll bp5 = b < 0 ? -pow5.ary[-b] : pow5.ary[b];
            if (ap5 - bp5 == X)
            {
                printf("%lld %lld\n", a, b);
                return 0;
            }
        }
    }
}
