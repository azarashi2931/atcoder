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
    string s;
    cin >> s;

    ll ans = 0;
    ll cnt = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] == 'R')
            cnt++;
        else
        {
            ans = max(cnt, ans);
            cnt = 0;
        }
    }
    ans = max(cnt, ans);

    printf("%lld\n", ans);
}
