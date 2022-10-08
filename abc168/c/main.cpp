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
#include <cmath>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

const double PI = 3.14159265358979323846;

int main()
{
    ll A, B, H, M;
    scanf("%lld %lld %lld %lld", &A, &B, &H, &M);

    double mt = (double)M * PI / 30.0;
    double ht = (double)H * PI / 6.0 + mt / 12.0;

    double x = (double)A * cos(ht) - (double)B * cos(mt);
    double y = (double)A * sin(ht) - (double)B * sin(mt);
    double ans = sqrt(x * x + y * y);

    printf("%.20lf\n", ans);
}
