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
#include <functional>
#include <cassert>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

template <typename T>
struct edge
{
};

ll binary_search_function(ll size, function<bool(ll)> check)
{
    ll left = 0;
    ll right = size;
    while (right - left > 1)
    {
        ll mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid;
    }

    return right;
}

template <typename T>
struct node
{
    node *parent, *left, *right;
    T value;
};

template <typename T>
struct binary_tree
{
    node<T> *root;
    void preorder_walk(const node<T> *current, function<void(const &node<T>)> func)
    {
        if (current == nullptr)
            return nullptr;

        func(current);
        preorder_walk(current->left, func);
        preorder_walk(current->right, func);
    }
    void inorder_walk(const node<T> *current, function<void(const &node<T>)> func)
    {
        if (current == nullptr)
            return nullptr;

        preorder_walk(current->left, func);
        func(current);
        preorder_walk(current->right, func);
    }
    void postorder_walk(const node<T> *current, function<void(const &node<T>)> func)
    {
        if (current == nullptr)
            return nullptr;

        preorder_walk(current->left, func);
        preorder_walk(current->right, func);
        func(current);
    }
    void reconstruction(iterator<node<T>> preorder_begin, iterator<node<T>> preorder_end)
    {
        auto root = begin;
        return root;
    }
};

int main()
{
    ll N;
    scanf("%lld", &N);

    vector<ll> A(3 * N);
    for (ll i; i < 3 * N; i++)
        scanf("%lld", &A[i]);

    ll ans = 0;
    printf("%lld\n", ans);
}
