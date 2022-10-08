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

int main()
{
    ll N, X, T;
    scanf("%lld", &N);
    scanf("%lld", &X);
    scanf("%lld", &T);

    ll ans = N / X + (N % X > 0 ? 1 : 0);
    printf("%lld\n", ans * T);
}
