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

    string s, t;
    cin >> s >> t;

    ll ans = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
            ans++;
    }
    printf("%lld\n", ans);
}
