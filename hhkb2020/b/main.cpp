#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <tuple>
#include <cassert>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

#define read_int(X) \
    ll X;           \
    scanf("%lld\n", &X);

#define read_two_int(X, Y) \
    ll X, Y;               \
    scanf("%lld %lld\n", &X, &Y);

#define read_three_int(X, Y, Z) \
    ll X, Y, Z;                 \
    scanf("%lld %lld %lld\n", &X, &Y, &Z);

#define read_four_int(X, Y, Z, W) \
    ll X, Y, Z, W;                \
    scanf("%lld %lld %lld %lld\n", &X, &Y, &Z, &W);

int main()
{
    read_two_int(H, W);
    ll ans = 0;
    vector<vector<bool>> isEmpty(H, vector<bool>(W));
    for (ll i = 0; i < H; i++)
    {
        string s;
        cin >> s;
        for (ll j = 0; j < W; j++)
        {
            isEmpty[i][j] = s[j] == '.';
            if (!isEmpty[i][j])
                continue;
            if (i > 0 && isEmpty[i - 1][j])
                ans++;
            if (j > 0 && isEmpty[i][j - 1])
                ans++;
        }
    }
    printf("%lld\n", ans);
}
