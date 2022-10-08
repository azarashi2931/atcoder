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

int main()
{
    ll K;
    scanf("%lld", &K);

    string s;
    cin >> s;

    for (ll i = 0; i < min(K, (ll)s.length()); i++)
    {
        printf("%c", s[i]);
    }

    if (s.length() > K)
        printf("...");
}
