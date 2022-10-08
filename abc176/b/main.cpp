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
    /*ll N;
    scanf("%lld", &N);

    ll d = 10;
    ll sum = 0;
    while (N > 0)
    {
        sum += N % d;
        N -= N % d;
        d *= 10;
    }*/

    char c;
    scanf("%c", &c);
    ll sum = 0;
    while (c != '\n')
    {
        sum += c - '0';
        scanf("%c", &c);
    }
    if (sum % 9 == 0)
        printf("Yes\n");
    else
        printf("No\n");
}
