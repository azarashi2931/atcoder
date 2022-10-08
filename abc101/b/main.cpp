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

    long long int N1 = N;
    long long int d = 1;
    long long int sum = 0;
    while (N1 > 0)
    {
        long long int x = (N1 / d) % 10;
        N1 -= x * d;
        sum += x;
        d *= 10;
    }

    if (N % sum == 0)
        printf("Yes");
    else
        printf("No");
}
