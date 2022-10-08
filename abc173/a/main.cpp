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

    ll ans = 1000 - (N % 1000);
    ans %= 1000;
    printf("%lld\n", ans);
}
