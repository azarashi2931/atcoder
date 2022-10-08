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

    ll th = 26;
    ll i;
    for (i = 0; i < 100; i++)
    {
        if (N <= th)
        {
            break;
        }
        N -= th;
        th *= 26;
    }

    if (N != 0)
    {
        N -= 1;
        i++;
    }
    //printf("%lld %lld %lld\n", N, i, th);
    //i文字
    vector<char> ans(i);
    for (ll j = 0; j < i; j++)
    {
        ll k = N / (th / 26);
        //printf("\n%lld %lld %lld ", N, th, k);

        printf("%c", (char)((ll)'a' + k));
        th /= 26;
        N -= k * th;
    }
    printf("\n");
}
