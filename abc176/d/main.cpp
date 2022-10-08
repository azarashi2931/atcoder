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
#include <set>
#include <tuple>
#include <cassert>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

#define read_intpair(X, Y) \
    ll X, Y;               \
    scanf("%lld %lld\n", &X, &Y);

//通行可能をtrueとする
constexpr char WallCharacter = '#';
vector<vector<bool>> read_grid_map(ll H, ll W)
{
    vector<vector<bool>> grid(H, vector<bool>(W));
    char c;
    for (ll i = 0; i < H; i++)
    {
        char c;
        for (ll j = 0; j < W; j++)
        {
            scanf("%c", &c);
            grid[i][j] = (c != WallCharacter);
        }
        scanf("%c", &c);
    }
    return grid;
}

struct movable_grid
{
    ll cost;
    pair<ll, ll> relative;
};

vector<vector<ll>> bfs_grid_shotest_path(vector<vector<bool>> gridmap, pair<ll, ll> start, list<movable_grid> searchgrid)
{
    const ll first_edge = gridmap.size();
    const ll second_edge = gridmap[0].size();

    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> nexts;
    nexts.push({0, {start.first, start.second}});
    vector<vector<ll>> mincostmap(first_edge, vector<ll>(second_edge, __LONG_LONG_MAX__));
    while (!nexts.empty())
    {
        auto current = nexts.top();
        nexts.pop();
        for (auto &&grid : searchgrid)
        {
            pair<ll, ll> currentpos = current.second;
            currentpos.first += grid.relative.first;
            currentpos.second += grid.relative.second;
            ll cost = current.first;
            if (currentpos.first < 0 || currentpos.second < 0 || currentpos.first >= first_edge || currentpos.second >= second_edge)
                continue;

            if (!gridmap[currentpos.first][currentpos.second])
                continue;

            cost += grid.cost;
            if (mincostmap[currentpos.first][currentpos.second] > cost)
            {
                mincostmap[currentpos.first][currentpos.second] = cost;
                nexts.push({cost, {currentpos.first, currentpos.second}});
            }
        }
    }

    return mincostmap;
}

int main()
{
    read_intpair(H, W);
    read_intpair(CH, CW);
    read_intpair(DH, DW);
    CH--;
    CW--;
    DH--;
    DW--;

    vector<vector<bool>> mazemap = read_grid_map(H, W);

    ll ans = 127;
    if (!mazemap[CH][CW])
    {
        ans = -1;
        printf("%lld\n", ans);
        return 0;
    }

    list<movable_grid> movable;
    for (ll i = -2; i < 3; i++)
    {
        for (ll j = -2; j < 3; j++)
        {
            ll cost;
            if (abs(i) > 1 || abs(j) > 1 || abs(i) == abs(j))
                cost = 1;
            else
                cost = 0;
            movable.push_back({cost, {i, j}});
        }
    }

    vector<vector<ll>> depthmap = bfs_grid_shotest_path(mazemap, {CH, CW}, movable);
    ans = depthmap[DH][DW];
    if (ans == __LONG_LONG_MAX__)
        ans = -1;
    printf("%lld\n", ans);
}
