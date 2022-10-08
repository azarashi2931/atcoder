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
    vector<ll> A(3);
    scanf("%lld %lld %lld", &(A[0]), &(A[1]), &(A[2]));

    sort(A.begin(), A.end());
    ll ans = A[2] - A[0];
    printf("%lld", ans);
}
