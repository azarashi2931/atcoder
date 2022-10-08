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
    string s;
    cin >> s;

    ll last = s[s.length() - 1] - '0';
    if (last == 3)
        printf("bon");
    else if (last == 2 || last == 4 || last == 5 || last == 7 || last == 9)
        printf("hon");
    else
    {
        printf("pon");
    }
}
