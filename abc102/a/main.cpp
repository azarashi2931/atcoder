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
    long long int N;
    scanf("%lld", &N);

    if (N % 2 != 0)
        N *= 2;

    printf("%lld", N);
}
