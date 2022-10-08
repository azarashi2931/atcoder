#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <bitset>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ll H, W, K;
    scanf("%lld %lld %lld\n", &H, &W, &K);

    vector<vector<bool>> inmap(H, vector<bool>(W));
    for (ll i = 0; i < H; i++)
    {
        for (ll j = 0; j < W; j++)
        {
            char c;
            scanf("%c", &c);
            if (c != '#' && c != '.')
                c = '?';
            inmap[i][j] = (c == '#');
        }

        scanf("\n");
    }

    const ll max = pow(2, H + W);
    ll ans = 0;
    for (ll k = 0; k < max; k++)
    {
        ll count = 0;
        //cout << bitset<12>(k);
        for (ll i = 0; i < H; i++)
        {
            if (((k >> i) & 1))
            {
                continue;
            }

            for (ll j = 0; j < W; j++)
            {
                /*printf(" ");
                cout << bitset<12>(k >> i);
                printf(" ");
                cout << bitset<12>(k >> (H + j));
                printf(" %lld %lld ", (k >> i) & 1, (k >> (H + j)) & 1);
                printf(" %lld %lld ", i, j);
                printf(" %lld ", inmap[i][j]);*/
                if (!((k >> (H + j)) & 1) && inmap[i][j])
                {
                    //printf(" (%lld,%lld)", i + 1, j + 1);
                    count++;
                }
            }
        }

        //printf(" %lld %lld", (k >> 0) & 1, (k >> (H + 0)) & 1);
        //printf(" %d", inmap[1][1] == true);
        //printf(" %d", inmap[2][1] == true);
        //printf(" %lld\n", count);
        if (count == K)
            ans++;
    }

    printf("%lld\n", ans);
}
