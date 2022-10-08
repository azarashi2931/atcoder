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
#include <random>
#include <cassert>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

struct HashPair
{
    static size_t m_hash_pair_random;

    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= m_hash_pair_random + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

size_t HashPair::m_hash_pair_random = (size_t)random_device()();

int main()
{
    ll H, W, M;
    scanf("%lld", &H);
    scanf("%lld", &W);
    scanf("%lld", &M);

    unordered_map<ll, ll> lineTargets, rowTargets;
    unordered_set<pair<ll, ll>, HashPair> targetMap;
    for (ll i = 0; i < M; i++)
    {
        ll h, w;
        scanf("%lld", &h);
        scanf("%lld", &w);
        h--;
        w--;
        lineTargets[h]++;
        rowTargets[w]++;
        targetMap.insert({h, w});
    }

    vector<pair<ll, ll>> lineVector(lineTargets.begin(), lineTargets.end());
    vector<pair<ll, ll>> rowVector(rowTargets.begin(), rowTargets.end());
    sort(lineVector.begin(), lineVector.end(), [](auto const &lhs, auto const &rhs) { return lhs.second > rhs.second; });
    sort(rowVector.begin(), rowVector.end(), [](auto const &lhs, auto const &rhs) { return lhs.second > rhs.second; });
    auto line = *lineVector.begin();
    auto row = *rowVector.begin();
    bool isNone = false;
    for (auto &&i : lineVector)
    {
        if (i.second < line.second)
            break;
        for (auto &&j : rowVector)
        {
            if (j.second < row.second)
                break;

            if (targetMap.find({i.first, j.first}) == targetMap.end())
            {
                isNone = true;
                break;
            }
        }
    }

    ll ans = line.second + row.second - (isNone ? 0 : 1);
    printf("%lld\n", ans);
}
