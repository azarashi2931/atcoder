#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    long long int N, K;
    scanf("%lld %lld", &N, &K);

    long long int block = (N - 1) / (K - 1);
    long long int amari = (N - 1) % (K - 1);

    printf("%d", block + (amari == 0 ? 0 : 1));
}
