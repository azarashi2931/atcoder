#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ll N;
    scanf("%lld", &N);

    vector<string> slist(N);
    for (ll i = 0; i < N; i++)
        cin >> slist[i];

    sort(slist.begin(), slist.end());
    ll ans = std::distance(slist.begin(), unique(slist.begin(), slist.end()));

    printf("%lld", ans);
}
