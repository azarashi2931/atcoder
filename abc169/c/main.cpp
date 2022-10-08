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
using ull = unsigned long long;
const int mod = 1e9 + 7;

int main()
{
    ull A, Bx100;
    double B;
    scanf("%llu %lf", &A, &B);
    Bx100 = B * 100;

    ull res;
    if (Bx100 > LLONG_MAX / A)
        ;
    else
        res = A * Bx100;

    if (A * Bx100 != 0)
        res /= 100;
    printf("%llu\n", res);
}
