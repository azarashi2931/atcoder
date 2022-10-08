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
    vector<vector<bool>> graph(H, vector<bool>(W, 0));
    for (ll i = 0; i < H; i++)
    {
        for (ll j = 0; j < W; j++)
        {
            char c;
            scanf("%c", &c);
            if (c == '#')
                graph[i][j] = true;
        }

        //\n
        char c;
        scanf("%c", &c);
    }

    pair<pair<ll, ll>, pair<ll, ll>> next = {{0, 0}, {0, 0}};
    for (ll i = 0; i < H; i++)
    {
        for (ll j = 0; j < W; j++)
        {
            if (graph[i][j])
            {
                next = {{i, j}, {i, j}};
                break;
            }
        }

        pair<pair<ll, ll>, pair<ll, ll>> zero = {{0, 0}, {0, 0}};
        if (next != zero)
            break;
    }

    ll ans = 0;
    vector<vector<bool>> mark(H, vector<bool>(W, 0));
    while (true)
    {
        auto previous = next.first;
        auto current = next.second;
        if (mark[current.first][current.second])
            continue;

        mark[current.first][current.second] = true;

        if (graph[current.first - 1][current.second] && !mark[current.first - 1][current.second])
        {
            bool isNearWhite = !(graph[current.first - 2][current.second] &&
                                 graph[current.first][current.second] &&
                                 graph[current.first - 1][current.second - 1] &&
                                 graph[current.first - 1][current.second + 1]);
            if (isNearWhite)
            {
                if (previous.first - current.first != 1 || previous.second - current.second != 0)
                    ans++;
                next = {current, {current.first - 1, current.second}};
                continue;
            }
        }

        if (graph[current.first][current.second - 1] && !mark[current.first][current.second - 1])
        {
            bool isNearWhite = !(graph[current.first - 1][current.second - 1] &&
                                 graph[current.first + 1][current.second - 1] &&
                                 graph[current.first][current.second - 2] &&
                                 graph[current.first][current.second]);
            if (isNearWhite)
            {
                if (previous.first - current.first != 0 || previous.second - current.second != 1)
                    ans++;
                next = {current, {current.first, current.second - 1}};
                continue;
            }
        }
        if (graph[current.first + 1][current.second] && !mark[current.first + 1][current.second])
        {
            bool isNearWhite = !(graph[current.first][current.second] &&
                                 graph[current.first + 2][current.second] &&
                                 graph[current.first][current.second - 1] &&
                                 graph[current.first][current.second + 1]);
            if (isNearWhite)
            {
                if (previous.first - current.first != -1 || previous.second - current.second != 0)
                    ans++;
                next = {current, {current.first + 1, current.second}};
                continue;
            }
        }
        if (graph[current.first][current.second + 1] && !mark[current.first][current.second + 1])
        {
            bool isNearWhite = !(graph[current.first - 1][current.second] &&
                                 graph[current.first + 1][current.second] &&
                                 graph[current.first][current.second] &&
                                 graph[current.first][current.second + 2]);
            if (isNearWhite)
            {
                if (previous.first - current.first != 0 || previous.second - current.second != -1)
                    ans++;
                next = {current, {current.first, current.second + 1}};
                continue;
            }
        }

        break;
    }

    printf("%lld\n", ans);
}
