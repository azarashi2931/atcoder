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

template <int M>
struct PrimeNumbers
{
    ll ary[M];
    constexpr PrimeNumbers() : ary()
    {
        ary[0] = 2;
        for (ll i = 1; i < M; i++)
        {
            ary[i] = i;
            bool isP = true;
            ll j = ary[i - 1] + 1;
            while (true)
            {
                for (ll k = 0; k < i; k++)
                {
                    if (j % ary[k] == 0)
                    {
                        isP = false;
                        break;
                    }
                }
                if (isP)
                    break;

                j++;
                if (j > 55555)
                    break;
            }

            ary[i] = j;
        }
    }
};

int main()
{
    PrimeNumbers<55> source;
    ll N;
    scanf("%lld", &N);

    printf("%lld", source.ary[0]);
    for (ll i = 1; i < N; i++)
        printf(" %lld", source.ary[i]);
    printf("\n");
}
