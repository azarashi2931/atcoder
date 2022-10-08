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
    string s, t;
    cin >> s;
    cin >> t;

    if (s.length() + 1 == t.length())
    {
        for (ll i = 0; i < s.length(); i++)
        {
            if (s[i] != t[i])
            {
                printf("No");
                return 0;
            }
        }

        printf("Yes");
        return 0;
    }

    printf("No");
}
