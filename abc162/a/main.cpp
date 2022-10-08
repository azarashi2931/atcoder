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

    if (N >= 700 && N < 800)
    {
        printf("Yes");
        return 0;
    }

    if (N % 100 >= 70 && N % 100 < 80)
    {
        printf("Yes");
        return 0;
    }

    if (N % 10 == 7)
    {
        printf("Yes");
        return 0;
    }

    printf("No");
}
