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

    ll ac = 0, wa = 0, tle = 0, re = 0;
    for (ll i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        if (s == "AC")
            ac++;
        else if (s == "WA")
        {
            wa++;
        }
        else if (s == "TLE")
        {
            tle++;
        }
        else if (s == "RE")
        {
            re++;
        }
    }

    printf("AC x %lld\n", ac);
    printf("WA x %lld\n", wa);
    printf("TLE x %lld\n", tle);
    printf("RE x %lld\n", re);
}
